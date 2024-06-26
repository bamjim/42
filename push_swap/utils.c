/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:01:31 by mku               #+#    #+#             */
/*   Updated: 2024/06/26 22:43:24 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *error)
{
	write(2, error, 7);
	exit(1);
}

void	print_list(t_stacks *stacks)
{
	int	count;
	t_node	*a_head;
	t_node	*b_head;

	a_head = stacks->a_stack->head;
	b_head = stacks->b_stack->head;
	if (stacks->a_stack->count <= stacks->b_stack->count)
		count = stacks->b_stack->count;
	else
		count = stacks->a_stack->count;
	for (int i = 0 ; i < count; i ++)
	{
		if (stacks->a_stack->head != NULL)
		{
			printf(" %d ",stacks->a_stack->head->number);
			stacks->a_stack->head = stacks->a_stack->head->next;
		}
		else
			printf("null");
		printf("    ");
		if (stacks->b_stack->head != NULL)
		{
			printf(" %d \n",stacks->b_stack->head->number);
			stacks->b_stack->head = stacks->b_stack->head->next;
		}
		else
			printf("null\n");
	}
	printf("[%d]   [%d]\n",stacks->a_stack->count,stacks->b_stack->count);
	stacks->a_stack->head = a_head;
	stacks->b_stack->head = b_head;
}

void	set_head_tail(t_stacks *stacks)
{
	stacks->a_stack = stacks->head;
	stacks->b_stack = stacks->tail;
}