/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:45:40 by mku               #+#    #+#             */
/*   Updated: 2024/11/15 19:17:16 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"
#include "builtin.h"
#include "export.h"

//export water="abc"
int	check_grammer(t_tokken_list *tokken, t_grammer_list *g_list);

int	export(t_tokken_list *tokken, t_stat *stat)
{
	if (ft_strncmp(tokken->content, "export", 6))
		return (FAIL_TO_FIND_CMD);
	if (check_grammer(tokken->next, stat->grammer_list))
	{
		print_env(stat->envlist);
		return (COMPLETE);
	}
	
}

int	check_grammer(t_tokken_list *tokken, t_grammer_list *g_list)
{
	t_grammer_list *list;

	list = g_list;
	while (list != NULL)
	{
		if (!ft_strncmp(tokken->content, list->content, ft_strlen(list->content)))
			return (1);
		list = list->next;
	}
	return (0);
}

