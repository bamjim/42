/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:59:09 by mku               #+#    #+#             */
/*   Updated: 2024/07/05 16:19:44 by mku              ###   ########.fr       */
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
		write(1,"sa\n",3);
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
		write(1,"sb\n",3);
	}
}

void	ss(t_stacks *stacks)
{
	sa(stacks->a);
	sb(stacks->b);
	write(1,"ss\n",3);
}

void	pa(t_stacks *stacks)
{
	t_node	*temp;

	if (stacks->b->count == 0)
		return ;
	temp = stacks->b->head;
	stacks->b->head = stacks->b->head->next;
	if (stacks->b->count != 1)
	stacks->b->head->prev = NULL;
	stacks->b->count--;
	if (stacks->a->count == 0)
	{
		stacks->a->head = temp;
		stacks->a->tail = temp;
		stacks->a->count++;
		temp->next = NULL;
		temp->prev = NULL;
		write(1,"pa\n",3);
		return ;
	}
	temp->next = stacks->a->head;
	stacks->a->head->prev = temp;
	temp->prev = NULL;
	stacks->a->head = temp;
	stacks->a->count++;
	write(1,"pa\n",3);
}

void	pb(t_stacks *stacks)
{
	t_node	*temp;

	if (stacks->a->count == 0)
		return ;
	temp = stacks->a->head;
	stacks->a->head = stacks->a->head->next;
	if (stacks->a->count != 1)
		stacks->a->head->prev = NULL;
	stacks->a->count--;
	if (stacks->b->count == 0)
	{
		stacks->b->head = temp;
		stacks->b->tail = temp;
		stacks->b->count++;
		temp->next = NULL;
		temp->prev = NULL;
		write(1,"pb\n",3);
		return ;
	}
	temp->next = stacks->b->head;
	stacks->b->head->prev = temp;
	temp->prev = NULL;
	stacks->b->head = temp;
	stacks->b->count++;
	write(1,"pb\n",3);
}
