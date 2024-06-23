/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:45:31 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 20:49:41 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	push_back(t_deque *deque, int number)
{
	t_node *newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
		return ;
	newnode->number = number;
	if (deque->count == 0)
	{
		deque->head = newnode;
		deque->tail = newnode;
		deque->count++;
	}
	deque->tail->next = newnode;
	newnode->prev = deque->tail;
	deque->tail = newnode;
}