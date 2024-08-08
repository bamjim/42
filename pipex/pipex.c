/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:46:50 by mku               #+#    #+#             */
/*   Updated: 2024/08/08 20:05:19 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(char **argv, char **envp, t_all *all, int *pipe);
static void	child2(char **argv, char **envp, t_all *all, int *pipe);
static void	fork_g_child(t_all *all, char **argv, char **envp, int *pipe_fd);
void		error(char *a);

int	main(int argc, char **argv, char **envp)
{
	t_all	all;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error("pipe error\n");
	if (argc != 5)
		error("wrong arg\n");
	split_cmd(&all, argv);
	find_path(envp, &all);
	all.pid = fork();
	if (all.pid == -1)
		error("fork error\n");
	else if (all.pid == 0)
		child(argv, envp, &all, pipe_fd);
	else
	{
		fork_g_child(&all, argv, envp, pipe_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(all.pid, NULL, 0);
		waitpid(all.pid2, NULL, 0);
		free_var(&all);
	}
}

static void	fork_g_child(t_all *all, char **argv, char **envp, int *pipe_fd)
{
	all->pid2 = fork();
	if (all->pid2 == -1)
		error("fork error\n");
	else if (all->pid2 == 0)
		child2(argv, envp, all, pipe_fd);
}

static void	child(char **argv, char **envp, t_all *all, int *pipe)
{
	int		fd;

	all->path = get_path(all, all->cmd);
	if (all->path == NULL)
		error("command not found\n");
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		error("no such file");
	close(pipe[0]);
	dup2(pipe[1], 1);
	dup2(fd, 0);
	close(fd);
	if (execve(all->path, all->sp_cmd, envp) == -1)
		perror("mku");
}

static void	child2(char **argv, char **envp, t_all *all, int *pipe)
{
	int		fd;

	all->path2 = get_path(all, all->cmd2);
	if (all->path2 == NULL)
		error("command not found\n");
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error("no such file");
	close(pipe[1]);
	dup2(pipe[0], 0);
	dup2(fd, 1);
	close(fd);
	if (execve(all->path2, all->sp_cmd2, envp) == -1)
		perror("mku");
}

void	error(char *a)
{
	write(2, a, ft_strlen(a));
	exit(1);
}
