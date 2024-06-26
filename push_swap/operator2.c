/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:21:27 by mku               #+#    #+#             */
/*   Updated: 2024/06/26 21:35:43 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a_stack)
{
	t_node	*t_head;
	t_node	*t_tail;

	if (a_stack->count > 1)
	{
	t_head = a_stack->head;
	t_tail = a_stack->tail;
	a_stack->head = a_stack->head->next;
	a_stack->tail = a_stack->tail->prev;
	a_stack->head->prev = NULL;
	a_stack->tail->next = NULL;
	t_tail->next = a_stack->head;
	a_stack->head->prev = t_tail;
	t_tail->prev = NULL;
	t_head->prev = a_stack->tail;
	a_stack->tail->next = t_head;
	t_head->next = NULL;
	a_stack->head = t_tail;
	a_stack->tail = t_head;
	}
}

void	rb(t_deque *b_stack)
{
	t_node	*t_head;
	t_node	*t_tail;

	if (b_stack->count > 1)
	{
	t_head = b_stack->head;
	t_tail = b_stack->tail;
	b_stack->head = b_stack->head->next;
	b_stack->tail = b_stack->tail->prev;
	b_stack->head->prev = NULL;
	b_stack->tail->next = NULL;
	t_tail->next = b_stack->head;
	b_stack->head->prev = t_tail;
	t_tail->prev = NULL;
	t_head->prev = b_stack->tail;
	b_stack->tail->next = t_head;
	t_head->next = NULL;
	b_stack->head = t_tail;
	b_stack->tail = t_head;
	}
}

void	rr(t_stacks *stacks)
{
	ra(stacks->a_stack);
	rb(stacks->b_stack);
}

void	rra(t_deque *a_stack)
{
	t_node	*temp;

	if (a_stack->count > 1)
	{
	temp = a_stack->tail;
	a_stack->tail = a_stack->tail->prev;
	a_stack->tail = NULL;
	temp->next = a_stack->head;
	a_stack->head->prev = temp;
	temp->prev = NULL;
	a_stack->head = temp;
	}
}

void	rrb(t_deque *b_stack)
{
	t_node	*temp;

	if (b_stack->count > 1)
	{
	temp = b_stack->tail;
	b_stack->tail = b_stack->tail->prev;
	b_stack->tail = NULL;
	temp->next = b_stack->head;
	b_stack->head->prev = temp;
	temp->prev = NULL;
	b_stack->head = temp;
	}
}