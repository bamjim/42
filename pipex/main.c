/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:46:50 by mku               #+#    #+#             */
/*   Updated: 2024/07/25 23:06:40 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_path(char **envp, t_all *all);

int main(int argc, char **argv, char **envp)
{
	t_all all;

	//if (argc != 5 )
	//{
	//	write(2, "wrong argv", 11);
	//	exit(1);
	//}
	find_path(envp, &all);
}

static void	find_path(char **envp, t_all *all)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			all->path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	i = 0;
	all->path_split = ft_split(all->path, ':');
	while (all->path_split[i] != NULL)
	{

	}
}

static void	set_all(char *cmd, char *cmd2, t_all *all)
{
	all->cmd = ft_strjoin("/", cmd);
	all->cmd2 = ft_strjoin("/", cmd2);
}
