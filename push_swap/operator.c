/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:59:09 by mku               #+#    #+#             */
/*   Updated: 2024/07/02 18:24:41 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a_stack)
{
	t_node	*second;
	t_node	*third;

	if (a_stack->count > 1)
	{
		second = a_stack->head->next;
		third = a_stack->head->next->next;
		a_stack->head->next = third;
		a_stack->head->prev = second;
		second->next = a_stack->head;
		second->prev = NULL;
		a_stack->head = second;
	}
}

void	sb(t_deque *b_stack)
{
	t_node	*second;
	t_node	*third;

	if (b_stack->count > 1)
	{
		second = b_stack->head->next;
		third = b_stack->head->next->next;
		b_stack->head->next = third;
		b_stack->head->prev = second;
		second->next = b_stack->head;
		second->prev = NULL;
		b_stack->head = second;
	}
}

void	ss(t_stacks *stacks)
{
	sa(stacks->a_stack);
	sb(stacks->b_stack);
}

void	pa(t_stacks *stacks)
{
	t_node	*temp;

	if (stacks->b_stack->count == 0)
		return ;
	temp = stacks->b_stack->head;
	stacks->b_stack->head = stacks->b_stack->head->next;
	stacks->b_stack->head->prev = NULL;
	stacks->b_stack->count--;
	if (stacks->a_stack->count == 0)
	{
		stacks->a_stack->head = temp;
		stacks->a_stack->tail = temp;
		stacks->a_stack->count++;
		temp->next = NULL;
		temp->prev = NULL;
		return ;
	}
	temp->next = stacks->a_stack->head;
	stacks->a_stack->head->prev = temp;
	temp->prev = NULL;
	stacks->a_stack->head = temp;
	stacks->a_stack->count++;
}

void	pb(t_stacks *stacks)
{
	t_node	*temp;

	if (stacks->a_stack->count == 0)
		return ;
	temp = stacks->a_stack->head;
	stacks->a_stack->head = stacks->a_stack->head->next;
	stacks->a_stack->head->prev = NULL;
	stacks->a_stack->count--;
	if (stacks->b_stack->count == 0)
	{
		stacks->b_stack->head = temp;
		stacks->b_stack->tail = temp;
		stacks->b_stack->count++;
		temp->next = NULL;
		temp->prev = NULL;
		return ;
	}
	temp->next = stacks->b_stack->head;
	stacks->b_stack->head->prev = temp;
	temp->prev = NULL;
	stacks->b_stack->head = temp;
	stacks->b_stack->count++;
}
