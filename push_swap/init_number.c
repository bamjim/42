/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:52 by mku               #+#    #+#             */
/*   Updated: 2024/07/17 17:39:06 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_dup(t_deque *a);
static void	check_dup2(int count, int *arr);

void	init_number_type1(t_stacks *stacks, char **s, int argc)
{
	int	num;
	int	i;
	int	j;

	i = 1;
	check_arg(s, argc);
	while (i < argc)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == ' ')
				j++;
			num = ft_atoi(s[i], &j);
			push_back(stacks->a, num);
		}
		i++;
	}
	check_dup(stacks->a);
}

void	init_number_type2(t_stacks *stacks, char **s)
{
	int		num;
	char	**temp;

	temp = s;
	check_arg_type2(*s);
	while (**temp != '\0')
	{
		if (**temp == ' ')
			(*temp)++;
		else
		{
			num = ft_atoi_type2(temp);
			push_back(stacks->a, num);
		}
	}
	check_dup(stacks->a);
}

static void	check_dup(t_deque *a)
{
	int		i;
	int		*arr;
	t_node	*temp;

	temp = a->head;
	arr = malloc(sizeof(int) * a->count);
	if (arr == NULL)
		error("error");
	i = 0;
	while (a->head != NULL)
	{
		arr[i] = a->head->number;
		i++;
		a->head = a->head->next;
	}
	a->head = temp;
	check_dup2(a->count, arr);
	free(arr);
}

static void	check_dup2(int count, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				error("error");
			j++;
		}
		i++;
	}
}
