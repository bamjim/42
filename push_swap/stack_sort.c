/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:39:54 by mku               #+#    #+#             */
/*   Updated: 2024/07/22 21:25:49 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_place(t_stacks *stacks);
static void	a_sort(t_stacks *stacks, int place);
int			is_sorted(t_list *a);

void	radix(t_stacks *stacks)
{
	int	place;

	place = find_place(stacks);
	a_sort(stacks, place);
}

static int	find_place(t_stacks *stacks)
{
	int	place;
	int	max;

	place = 0;
	max = stacks->a->max;
	while (max != 0)
	{
		max = max >> 1;
		place++;
	}
	return (place);
}

int	is_sorted(t_list *a)
{
	t_node	*temp;

	temp = a->head;
	while (a->head->next != NULL && a->head != NULL)
	{
		if (a->head->number > a->head->next->number)
		{
			a->head = temp;
			return (1);
		}
		a->head = a->head->next;
	}
	a->head = temp;
	return (0);
}

static void	a_sort(t_stacks *stacks, int place)
{
	int		i;
	int		j;
	int		a_count;
	t_node	*a_temp;

	i = 0;
	while (i < place)
	{
		a_count = stacks->a->count;
		while (a_count-- && is_sorted(stacks->a))
		{
			if (((stacks->a->head->number >> i) & 1) == 0)
				pb(stacks);
			else
				ra(stacks->a);
		}
		i++;
		while (stacks->b->head != NULL)
			pa(stacks);
	}
}
