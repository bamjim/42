/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:08:39 by mku               #+#    #+#             */
/*   Updated: 2024/07/16 19:37:36 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_case(int *arr, t_deque*a);

void	base_case_sort(t_deque *a)
{
	int		arr[3];
	int		i;
	t_node	*temp;

	temp = a->head;
	i = 0;
	if (a->count < 3)
	{
		if (a->head->number == a->head->next->number)
			error("error");
		if (a->head->number > a->head->next->number)
		{
			sa(a);
			return ;
		}
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

static void	check_case(int *arr, t_deque *a)
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
			case_312(a);
	}
	if (arr[0] < arr[1] && arr[0] > arr[2])
		case_231(a);
}