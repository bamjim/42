/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:45:45 by mku               #+#    #+#             */
/*   Updated: 2024/11/05 18:07:22 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"

static	void	print_pwd(t_tokken_list *tokken, t_envlist *envlist);

int	check_pwd(t_tokken_list *tokken, t_envlist *envlist)
{
	t_tokken_list *list;

	list = tokken;
	while(list != NULL)
	{
		if (!ft_strncmp(list->content, "pwd", 3))
		{
			print_pwd(list, envlist);
			return (1);
		}
		list = list->next;
	}
	return (0);
}

static	void	print_pwd(t_tokken_list *tokken, t_envlist *envlist)
{
	int	i;

	t_envlist *list;
	char *temp;

	list = envlist;
	while (list != NULL)
	{
		if (!ft_strncmp(list->content, "PWD=", 4))
		{
			temp = ft_substr(list->content, 4, ft_strlen(list->content));
			write(1, temp, ft_strlen(temp));
			write(1, "\n", 2);
			free(temp);
			return ;
		}
		list = list->next;
	}
}