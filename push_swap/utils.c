/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:01:31 by mku               #+#    #+#             */
/*   Updated: 2024/07/05 16:03:57 by mku              ###   ########.fr       */
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

	a_head = stacks->a->head;
	b_head = stacks->b->head;
	if (stacks->a->count <= stacks->b->count)
		count = stacks->b->count;
	else
		count = stacks->a->count;
	for (int i = 0 ; i < count; i ++)
	{
		if (stacks->a->head != NULL)
		{
			printf(" %d ",stacks->a->head->number);
			stacks->a->head = stacks->a->head->next;
		}
		else
			printf("null");
		printf("    ");
		if (stacks->b->head != NULL)
		{
			printf(" %d \n",stacks->b->head->number);
			stacks->b->head = stacks->b->head->next;
		}
		else
			printf("null\n");
	}
	printf("[%d]   [%d]\n",stacks->a->count,stacks->b->count);
	stacks->a->head = a_head;
	stacks->b->head = b_head;
}
