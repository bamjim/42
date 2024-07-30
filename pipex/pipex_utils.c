/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:04:49 by mku               #+#    #+#             */
/*   Updated: 2024/07/26 20:25:01 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_path(t_all *all, int i);
static void	init_path2(t_all *all, int i);

void	set_all(char *cmd, char *cmd2, t_all *all)
{
	char	**temp;

	all->cmd = cmd;
	all->cmd2 = cmd2;
	all->sp_cmd = ft_split(cmd, ' ');
	all->sl_cmd = ft_strjoin("/", all->sp_cmd[0]);
	all->sp_cmd2 = ft_split(cmd2, ' ');
	all->sl_cmd2 = ft_strjoin("/", all->sp_cmd2[0]);
}

void	find_path(char **envp, t_all *all)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			all->path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	all->path_split = ft_split(all->path, ':');
	init_path(all, 0);
	init_path2(all, 0);
}

static void	init_path(t_all *all, int i)
{
	char *temp;

	while (all->path_split[i] != NULL)
	{
		temp = ft_strjoin(all->path_split[i], all->sl_cmd);
		if (access(temp, X_OK) == 0)
		{
			all->path = ft_strdup(all->path_split[i]);
			break;
		}
		free(temp);
		i++;
	}
}

static void	init_path2(t_all *all, int i)
{
	char *temp;

	while (all->path_split[i] != NULL)
	{
		temp = ft_strjoin(all->path_split[i], all->sl_cmd2);
		if (access(temp, X_OK) == 0)
		{
			all->path2 = ft_strdup(all->path_split[i]);
			break;
		}
		free(temp);
		i++;
	}
	i = 0;
	while (all->path_split[i] != NULL)
	{
		free(all->path_split[i]);
		i++;
	}
}
