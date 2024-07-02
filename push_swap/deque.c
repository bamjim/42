/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:45:31 by mku               #+#    #+#             */
/*   Updated: 2024/07/02 18:26:25 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "push_swap.h"

void	push_back(t_deque *deque, int number)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
		return ;
	newnode->number = number;
	if (deque->count == 0)
	{
		deque->head = newnode;
		deque->tail = newnode;
		deque->count++;
		return ;
	}
	deque->tail->next = newnode;
	newnode->prev = deque->tail;
	newnode->next = NULL;
	deque->tail = newnode;
	deque->count++;
}

void	push_front(t_deque *deque, int number)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
		return ;
	newnode->number = number;
	if (deque->count == 0)
	{
		deque->head = newnode;
		deque->tail = newnode;
		deque->count++;
		return ;
	}
	newnode->next = deque->head;
	newnode->prev = NULL;
	deque->head->prev = newnode;
	deque->head = newnode;
	deque->count++;
}

int	pop_back(t_deque *deque)
{
	int		number;
	t_node	*prev_tail;

	number = deque->tail->number;
	prev_tail = deque->tail->prev;
	prev_tail->next = NULL;
	free(deque->tail);
	deque->tail = prev_tail;
	deque->count--;
	return (number);
}

int	pop_front(t_deque *deque)
{
	int		number;
	t_node	*next_head;

	number = deque->head->number;
	next_head = deque->head->next;
	next_head->prev = NULL;
	free(deque->head);
	deque->head = next_head;
	deque->count--;
	return (number);
}
