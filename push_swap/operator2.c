/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:21:27 by mku               #+#    #+#             */
/*   Updated: 2024/07/22 21:17:32 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *a_stack)
{
	t_node	*t_head;

	if (a_stack->count > 1)
	{
		t_head = a_stack->head;
		a_stack->head = a_stack->head->next;
		t_head->next = NULL;
		a_stack->head->prev = NULL;
		a_stack->tail->next = t_head;
		t_head->prev = a_stack->tail;
		a_stack->tail = t_head;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list *b_stack)
{
	t_node	*t_head;

	if (b_stack->count > 1)
	{
		t_head = b_stack->head;
		b_stack->head = b_stack->head->next;
		t_head->next = NULL;
		b_stack->head->prev = NULL;
		b_stack->tail->next = t_head;
		t_head->prev = b_stack->tail;
		b_stack->tail = t_head;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stacks *stacks)
{
	ra(stacks->a);
	rb(stacks->a);
	write(1, "rr\n", 3);
}

void	rra(t_list *a_stack)
{
	t_node	*temp;

	if (a_stack->count > 1)
	{
		temp = a_stack->tail;
		a_stack->tail = a_stack->tail->prev;
		a_stack->tail->next = NULL;
		temp->next = a_stack->head;
		a_stack->head->prev = temp;
		temp->prev = NULL;
		a_stack->head = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list *b_stack)
{
	t_node	*temp;

	if (b_stack->count > 1)
	{
		temp = b_stack->tail;
		b_stack->tail = b_stack->tail->prev;
		b_stack->tail->next = NULL;
		temp->next = b_stack->head;
		b_stack->head->prev = temp;
		temp->prev = NULL;
		b_stack->head = temp;
		write(1, "rrb\n", 4);
	}
}
