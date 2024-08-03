/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:04:49 by mku               #+#    #+#             */
/*   Updated: 2024/08/03 19:40:45 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*cmd_path_check(char *cmd);

void	set_all(char *cmd, char *cmd2, t_all *all)
{
	char	*t_cmd;
	char	*t_cmd2;

	t_cmd = cmd_path_check(cmd);
	all->sp_cmd = ft_split(t_cmd, ' ');
	all->sl_cmd = ft_strjoin("/", all->sp_cmd[0]);
	t_cmd2 = cmd_path_check(cmd2);
	all->sp_cmd2 = ft_split(t_cmd2, ' ');
	all->sl_cmd2 = ft_strjoin("/", all->sp_cmd2[0]);
	free(t_cmd);
	free(t_cmd2);
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
	free(all->path);
}

char	*init_path(t_all *all, int i, char *sl_cmd)
{
	char	*temp;

	while (all->path_split[i] != NULL)
	{
		temp = ft_strjoin(all->path_split[i], sl_cmd);
		if (access(temp, X_OK | F_OK) == 0)
		{
			free(temp);
			return (ft_strjoin(all->path_split[i], sl_cmd));
		}
		free(temp);
		i++;
	}
	return (NULL);
}

static char	*cmd_path_check(char *cmd)
{
	char	**temp;
	int		i;
	char	*result;

	i = 0;
	if (cmd[0] == '/')
	{
		temp = ft_split(cmd, '/');
		while (temp[i + 1] != NULL)
			i++;
		result = temp[i];
		i--;
		while (i >= 0)
		{
			free(temp[i]);
			i--;
		}
		free(temp);
		return (result);
	}
	return (ft_strdup(cmd));
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
