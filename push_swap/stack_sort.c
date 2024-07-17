/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:39:54 by mku               #+#    #+#             */
/*   Updated: 2024/07/17 18:27:20 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_deque *stack, int *pivot);

void	greedy(t_stacks *stacks)
{
	int	pivot[2];
	int	i;
	int	size;

	size = stacks->a->count;
	i = 0;
	set_pivot(stacks->a, pivot);
	while (i < size)
	{
		if (pivot[SMALL] >= stacks->a->head->number)
		{
			pb(stacks);
			rb(stacks->b);
		}
		if (pivot[BIG] >= stacks->a->head->number)
			pb(stacks);
		else
			ra(stacks->a);
		i++;
	}
	while (stacks->a->count > 3)
		pb(stacks);
	base_case_sort(stacks->a);
	print_list(stacks);
}

void	set_pivot(t_deque *stack, int *pivot)
{
	int	*arr;
	int	size;
	t_node	*temp;

	size = 0;
	arr = NULL;
	temp = stack->head;
	if (stack->count == 2 && stack->head->number > stack->tail->number)
	{
		pivot[BIG] = stack->head->number;
		return ;
	}
	arr = malloc(sizeof(int) * stack->count);
	if (arr == NULL)
		error("malloc error");
	while (temp != NULL)
	{
		arr[size] = temp->number;
		temp = temp->next;
		size++;
	}
	sort(arr, 0, size);
	pivot[BIG] = arr[size/3 * 2];
	pivot[SMALL] = arr[(size / 3)];
	free(arr);
}

void	find_best(t_stacks *stacks)
{
	t_oper *oper;
	int	i;

	i = 0;
	oper = (t_oper *)malloc(sizeof(t_oper) * stacks->b->count);
	if (oper == NULL)
		error("error");
	while (stacks->b->head != NULL)
	{

	}
}