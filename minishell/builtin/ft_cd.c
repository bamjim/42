/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:07 by mku               #+#    #+#             */
/*   Updated: 2024/11/20 14:58:09 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"

static char	*find_cd_command(t_tokken_list *list);
static void	absolute_path(char *path, t_envlist *envlist);
static void	relative_path(char *path, t_envlist *envlist);

int	change_directory(t_tokken_list *list, t_stat *stat)
{
	char	*path;
	char	*home_dir;
	int		ret;
	printf("afsdvdv\n");
	path = find_cd_command(list);
	if (path == NULL)
		return (FAIL_TO_FIND_CMD);
	if (path[0] == '~')
	{
		home_dir = find_home_dir(stat->envlist);
		ret = chdir(home_dir);
		if (ret)
			write(2, "cd : no such file or directory\n ", 33);
		free(home_dir);
	}
	else if (path[0] == '.' && path[1] == '/')
		absolute_path(path, stat->envlist);
	else
		relative_path(path, stat->envlist);
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

	temp = getcwd(NULL, 0);
	ret = chdir(path);
	if (ret)
		write(2, "cd : no such file or directory\n ", 33);
	else
		change_pwd(envlist, path);
	//free(temp);
}

static void	relative_path(char *path, t_envlist *envlist)
{
	char	*current_path;
	char	*join_path;
	char	*temp;
	//t_envlist *list;
	printf("asdfsdfa\n");
	//list = *envlist;
	temp = getcwd(NULL, 0);
	current_path = ft_strjoin(temp, "/");
	if (current_path == NULL)
		write(2, "getcwd error", 13);
	join_path = ft_strjoin(current_path, path);
	if (chdir(join_path))
		write(2, "cd : no such file or directory\n ", 33);
	else
		change_pwd(envlist, join_path);
	//free(temp);
	//free(join_path);
}
