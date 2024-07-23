/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:01:31 by mku               #+#    #+#             */
/*   Updated: 2024/07/23 16:21:59 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *error)
{
	write(2, error, 6);
	exit(1);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	init_arr(int *arr, t_list *temp)
{
	int		i;
	t_node	*head;

	head = temp->head;
	i = 0;
	while (i < temp->count)
	{
		arr[i] = temp->head->number;
		i++;
		temp->head = temp->head->next;
	}
	temp->head = head;
	sort(arr, 0, temp->count - 1);
}

void	check(t_stacks *stacks)
{
	check_dup(stacks->a);
	set_rank(stacks->a);
	stacks->a->max = stacks->a->count - 1;
}
