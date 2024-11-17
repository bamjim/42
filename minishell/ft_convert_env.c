/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:00:13 by mku               #+#    #+#             */
/*   Updated: 2024/11/11 17:19:51 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_test.h"

static int	count_env(t_envlist *envlist);
static char	**insert_char(t_envlist *envlist, char **result, int length);

char	**convert_env(t_envlist *envlist)
{
	int		length;
	char **result;
	length = count_env(envlist);
	result = (char **)malloc(sizeof(char *) * (length + 1));
	if (result == NULL)
		return (NULL);
	result = insert_char(envlist, result, length);

	return (result);
}

static int	count_env(t_envlist *envlist)
{
	int		count;
	t_envlist	*list;

	list = envlist;
	count = 0;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return (count);
}

static char	**insert_char(t_envlist *envlist, char **result, int length)
{
	t_envlist	*list;
	int	count;

	count = 0;
	list = envlist;
	while (count < length)
	{
		result[count] = list->content;
		list = list->next;
		count++;
	}
	result[count] = NULL;
	return (result);
}