/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:10 by mku               #+#    #+#             */
/*   Updated: 2024/11/15 16:42:22 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"

char	*find_home_dir(t_envlist *envlist)
{
	t_envlist *list;

	list = envlist;
	while (list != NULL)
	{
		if (strncmp(list->content, "HOME=", 6))
			return (ft_substr(list->content, 6, ft_strlen(list->content)));
		list = list->next;
	}
	return (NULL);
}

void	change_pwd(t_envlist *envlist, char *path)
{
	t_envlist *list;
	char	*old_pwd;
	char	*temp;

	list = envlist;
	old_pwd = getcwd(NULL, 0);
	while (envlist != NULL)
	{
		if (!strncmp(envlist->content, "PWD=", 4))
		{
			temp = envlist->content;
			envlist->content = ft_strjoin(ft_strdup("PWD="), path);
			free(temp);
			return ;
		}
		envlist = envlist->next;
	}
}

void	change_oldpwd(t_envlist *envlist, char *path)
{
	t_envlist *list;
	char	*temp;

	list = envlist;
	while (list != NULL)
	{
		if (strncmp(list->content, "OLDPWD=", 8))
		{
			temp = list->content;
			list->content = ft_strjoin("OLDPWD=", path);
			free(temp);
		}
		list = list->next;
	}
}