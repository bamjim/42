/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:04:49 by mku               #+#    #+#             */
/*   Updated: 2024/08/08 20:50:53 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_cmd(char *path, t_all *all);

void	find_path(char **envp, t_all *all)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			temp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	all->path_split = ft_split(temp, ':');
	free(temp);
}

char	*get_path(t_all *all, char *cmd)
{
	char	*temp;

	temp = NULL;
	if (cmd[0] != '.' && cmd[0] != '/')
	{
		temp = ft_strjoin("/", cmd);
		return (check_cmd(temp, all));
	}
	else
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

static char	*check_cmd(char *path, t_all *all)
{
	int		i;
	char	*temp;

	i = 0;
	while (all->path_split[i] != NULL)
	{
		temp = ft_strjoin(all->path_split[i], path);
		if (access(temp, X_OK) == 0)
		{
			free(path);
			return (temp);
		}
		free(temp);
		i++;
	}
	free(path);
	return (NULL);
}

void	split_cmd(t_all *all, char **argv)
{
	all->sp_cmd = ft_split(argv[2], ' ');
	all->cmd = all->sp_cmd[0];
	all->sp_cmd2 = ft_split(argv[3], ' ');
	all->cmd2 = all->sp_cmd2[0];
}

void	free_var(t_all *all)
{
	int	i;

	i = 0;
	while (all->sp_cmd[i] != NULL)
	{
		free(all->sp_cmd[i]);
		i++;
	}
	i = 0;
	while (all->sp_cmd2[i] != NULL)
	{
		free(all->sp_cmd2[i]);
		i++;
	}
	free(all->sp_cmd);
	free(all->sp_cmd2);
	i = 0;
	while (all->path_split[i] != NULL)
	{
		free(all->path_split[i]);
		i++;
	}
	free(all->path_split);
}
