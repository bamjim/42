/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:16:36 by mku               #+#    #+#             */
/*   Updated: 2024/11/12 18:47:47 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include "../String/ft_string.h"
#include <unistd.h>

void	lst_push_back(t_list *list, char *content, t_token_type type)
{
	t_node *newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
		return ;
	newnode->content = content;
	newnode->type = type;
	newnode->next = NULL;
	if (list->head == NULL)
	{
		list->head = newnode;
		list->tail = newnode;
		newnode->prev = NULL;
		list->count = 1;
	}
	else
	{
		list->tail->next = newnode;
		newnode->prev = list->tail;
		list->tail = newnode;
		list->count++;
	}
}

void	lst_push_front(t_list *list, char *content, t_token_type type)
{
	t_node *newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
		return ;
	newnode->content = content;
	newnode->prev = NULL;
	newnode->type = type;
	if (list->head == NULL)
	{
		list->head = newnode;
		list->tail = newnode;
		newnode->prev = NULL;
		list->count = 1;
	}
	else
	{
		newnode->next = list->head;
		list->head->prev = newnode;
		list->head = newnode;
		list->count++;
	}
}

t_node*	lst_find_content(t_list *list, char *content)
{
	t_node *head;

	head = list->head;
	while (head != NULL)
	{
		if (ft_strncmp(head->content, content, ft_strlen(content)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	print_list(t_list *list)
{
	t_node *head;

	head = list->head;
	while (head != NULL)
	{
		ft_print_fd(head->content, 1);
		head = head->next;
	}
}

void	lst_delete(t_list *list, char *content)
{
	t_node	*delete_node;

	if (list->head == NULL || list->count == 0)
		return ;
	delete_node = lst_find_content(list, content);
	if (delete_node == list->head)
		list->head = list->head->next;
	if (delete_node == list->tail)
		list->tail = list->tail->prev;
	if (delete_node->prev != NULL)
		delete_node->prev->next = delete_node->next;
	if (delete_node->next != NULL)
		delete_node->next->prev = delete_node->prev;
	free(delete_node->content);
	free(delete_node);
	list->count--;
	if (list->count == 0)
	{
		list->head = NULL;
		list->tail = NULL;
	}
}
