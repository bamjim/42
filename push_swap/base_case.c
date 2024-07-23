/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:08:39 by mku               #+#    #+#             */
/*   Updated: 2024/07/22 21:17:32 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_case(int *arr, t_list*a);
static void	five_utils(t_stacks *stacks, t_node *temp, int place, int i);

void	base_case_three(t_list *a)
{
	int		arr[3];
	int		i;
	t_node	*temp;

	temp = a->head;
	i = 0;
	if (a->count == 1)
		return ;
	if (a->count < 3)
	{
		if (a->head->number == a->head->next->number)
			error("error");
		if (a->head->number > a->head->next->number)
			sa(a);
		return ;
	}
	while (i < 3)
	{
		arr[i] = temp->number;
		temp = temp->next;
		i++;
	}
	if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2])
		error("error");
	check_case(arr, a);
}

static void	check_case(int *arr, t_list *a)
{
	if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		if (arr[1] > arr[2])
			case_132(a);
	}
	if (arr[0] > arr[1] && arr[0] > arr[2])
	{
		if (arr[1] > arr[2])
			case_321(a);
		else
		{
			case_312(a);
			return ;
		}
	}
	if (arr[0] < arr[1] && arr[0] > arr[2])
		case_231(a);
	if (arr[0] > arr[1] && arr[1] < arr[2])
		case_213(a);
}

void	base_case_five(t_stacks *stacks)
{
	t_node	*temp;
	int		place;
	int		i;

	i = 0;
	if (!is_sorted(stacks->a))
		return ;
	while (stacks->a->count > 3)
	{
		temp = stacks->a->head;
		place = 0;
		five_utils(stacks, temp, place, i);
		if (!is_sorted(stacks->a) && stacks->b->head == NULL)
			return ;
		pb(stacks);
		i++;
	}
	if (stacks->b->head != NULL)
	{
		base_case_three(stacks->a);
		while (stacks->b->head != NULL)
			pa(stacks);
	}
}

static void	five_utils(t_stacks *stacks, t_node *temp, int place, int i)
{
	while (temp->number != i)
	{
		temp = temp->next;
		place++;
	}
	if (place < 3)
	{
		while (place--)
			ra(stacks->a);
	}
	else
	{
		while (place > 2 && place < stacks->a->count)
		{
			rra(stacks->a);
			place++;
		}
	}
}
