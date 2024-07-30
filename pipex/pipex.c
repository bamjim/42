/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:46:50 by mku               #+#    #+#             */
/*   Updated: 2024/07/30 18:55:59 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(char **argv, char **envp, t_all *all, int *pipe);
static void	child2(char **argv, char **envp, t_all *all, int *pipe);

int main(int argc, char **argv, char **envp)
{
	t_all	all;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit(1);
	//if (argc != 5 )
	//{
	//	write(2, "wrong argv", 11);
	//	exit(1);
	//}
	set_all(argv[2], argv[3], &all);
	find_path(envp, &all);
	printf("%s       %s\n",all.path,all.path2);
	printf("%s       %s\n",all.sp_cmd2[0],all.sp_cmd2[1]);
	all.pid = fork();
	if (all.pid == -1)
		exit(1);
	else if (all.pid == 0)
		child(argv, envp, &all, pipe_fd);
	else
	{
		all.pid2 = fork();
		if (all.pid2 == -1)
			exit(1);
		else if (all.pid2 == 0)
			child2(argv, envp, &all, pipe_fd);
		else
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			waitpid(all.pid, NULL, 0);
			waitpid(all.pid, NULL, 0);
		}
	}
}

static void	child(char **argv, char **envp, t_all *all, int *pipe)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(1);
	printf("1fd      %d\n",fd);
	close(pipe[0]);
	dup2(pipe[1], 1);
	dup2(fd, 0);
	close(fd);
	printf("1  %d\n",execve(all->path, all->sp_cmd, envp));
	if (execve(all->path, all->sp_cmd, envp) == -1)
		printf("eeeeeee");
}

static void	child2(char **argv, char **envp, t_all *all, int *pipe)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(1);
	printf("2fd      %d\n",fd);
	close(pipe[1]);
	dup2(pipe[0], 0);
	dup2(fd, 1);
	close(fd);
	printf("2 / %d\n",execve(all->path, all->sp_cmd, envp));
	if (execve(all->path2, all->sp_cmd2, envp) == -1)
		printf("ddddddd");
}