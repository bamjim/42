/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:49:22 by mku               #+#    #+#             */
/*   Updated: 2024/06/26 22:34:05 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	int	pivot;
	int	i;
	int	count;

	count = stacks->a_stack->count;
	pivot = stacks->a_stack->head->number;
	while (i < count && stacks->a_stack->head != NULL)
	{
		if (pivot < stacks->a_stack->head->number)
		{
			pb(stacks);
		}
		stacks->a_stack->head = stacks->a_stack->head->next;
		i++;
	}
}