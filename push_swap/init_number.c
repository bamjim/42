/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:52 by mku               #+#    #+#             */
/*   Updated: 2024/07/23 16:20:55 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			while (s[i][j] == ' ')
				j++;
			if (s[i][j] == '\0')
				break ;
			num = ft_atoi(s[i], &j);
			push_back(stacks->a, num);
		}
		i++;
	}
	if (stacks->a->head == NULL)
		error(ERROR);
	if (stacks->a->count > 1)
		check(stacks);
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
			if (**temp == '\0')
				return ;
			num = ft_atoi_type2(temp);
			push_back(stacks->a, num);
		}
	}
	if (stacks->a->head == NULL)
		error(ERROR);
	if (stacks->a->count > 1)
		check(stacks);
}

void	check_dup(t_list *a)
{
	int		i;
	int		*arr;
	t_node	*temp;

	temp = a->head;
	arr = malloc(sizeof(int) * a->count);
	if (arr == NULL)
		error(ERROR);
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

void	check_dup2(int count, int *arr)
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
				error(ERROR);
			j++;
		}
		i++;
	}
}

void	set_rank(t_list *a)
{
	t_node	*temp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * a->count);
	if (arr == NULL)
		error(ERROR);
	temp = a->head;
	init_arr(arr, a);
	while (a->head != NULL)
	{
		i = 0;
		while (i < a->count)
		{
			if (a->head->number == arr[i])
			{
				a->head->number = i;
				break ;
			}
			i++;
		}
		a->head = a->head->next;
	}
	a->head = temp;
	free(arr);
}
