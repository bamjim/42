/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:07 by mku               #+#    #+#             */
/*   Updated: 2024/11/15 17:53:41 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"

static char	*find_cd_command(t_tokken_list *list);
static void	absolute_path(char *path, t_envlist *envlist);
static void	relative_path(char *path, t_envlist *envlist);

int	change_directory(t_tokken_list *list, t_envlist *envlist)
{
	char	*path;
	char	*home_dir;
	int		ret;

	path = find_cd_command(list);
	if (path == NULL)
		return (FAIL_TO_FIND_CMD);
	if (path[0] == '~')
	{
		home_dir = find_home_dir(envlist);
		ret = chdir(home_dir);
		if (ret)
			write(2, "cd : no such file or directory\n ", 33);
		free(home_dir);
	}
	else if (path[0] == '.' && path[1] == '/')
		absolute_path(path, envlist);
	else
		relative_path(path, envlist);
	return (COMPLETE);
}
static char	*find_cd_command(t_tokken_list *list)
{
	while(list != NULL)
	{
		if (!ft_strncmp(list->content, "cd", 2))
			return (list->next->content);
		list = list->next;
	}
	return (NULL);
}

static void	absolute_path(char *path, t_envlist *envlist)
{
	int	ret;
	t_envlist	*pwd;
	t_envlist	*oldpwd;
	char *temp;

	temp = getcwd(NULL, PATH_MAX);
	ret = chdir(path);
	if (ret)
		write(2, "cd : no such file or directory\n ", 33);
	else
	{
		change_oldpwd(envlist, temp);
		change_pwd(envlist, path);
	}
	free(temp);
}

static void	relative_path(char *path, t_envlist *envlist)
{
	char	*current_path;
	char	*join_path;
	int		ret;
	char	*temp;
	//t_envlist *list;

	//list = *envlist;
	temp = getcwd(NULL, PATH_MAX);
	current_path = ft_strjoin(temp, "/");
	if (current_path == NULL)
		write(2, "getcwd error", 13);
	join_path = ft_strjoin(current_path, path);
	printf("%s\n",join_path);
	ret = chdir(join_path);
	if (ret)
		write(2, "cd : no such file or directory\n ", 33);
	else
	{
		//change_oldpwd(envlist, temp);
		change_pwd(envlist, join_path);
	}
	//free(temp);
}
