/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:22 by mku               #+#    #+#             */
/*   Updated: 2024/11/15 17:53:13 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../ms_test.h"

void	print_env(t_envlist *envlist);

int	check_env(t_tokken_list *tokken, t_envlist *envlist)
{
	t_tokken_list *list;

	list = tokken;
	while(list != NULL)
	{
		if (!ft_strncmp(list->content, "env", 3))
		{
			print_env(envlist);
			return (COMPLETE);
		}
		list = list->next;
	}
	return (FAIL_TO_FIND_CMD);
}

void	print_env(t_envlist *envlist)
{
	int	i;

	t_envlist *list;

	list = envlist;
	i = 0;
	while (list != NULL)
	{
		write(1, list->content, ft_strlen(list->content));
		write(1, "\n", 2);
		list = list->next;
	}
}