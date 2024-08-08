/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:04:49 by mku               #+#    #+#             */
/*   Updated: 2024/08/08 18:48:15 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_all(char *cmd, char *cmd2, t_all *all)
{
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
		{
			all->path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	all->path_split = ft_split(all->path, ':');
	free(all->path);
}

char	*init_path(t_all *all, int i, char *sl_cmd, char *cmd)
{
	char	*temp;

	while (all->path_split[i] != NULL)
	{
		if (cmd[0] != '/')
			temp = ft_strjoin(all->path_split[i], sl_cmd);
		else
			temp = ft_strdup(sl_cmd);
		if (access(temp, X_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}

void	free_var(t_all *all)
{
	int	i;

	i = 0;
	free(all->sl_cmd2);
	free(all->sl_cmd);
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
