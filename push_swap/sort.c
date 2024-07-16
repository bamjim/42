/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:49:22 by mku               #+#    #+#             */
/*   Updated: 2024/07/16 18:04:01 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_arr(t_stacks *a_stack);
void	sort(int	*arr, int left, int right);
static int		set_pivot(int *arr, int left, int rigth);

void	sort(int	*arr, int left, int right)
{
	int	pivot;

	if (left > right)
		return ;
	pivot = set_pivot(arr, left, right);
	sort(arr, left, pivot -1);
	sort(arr, pivot + 1, right);
}

void	set_arr(t_stacks *stacks)
{
	int		*result;
	int		i;
	t_node	*head;

	i = 0;
	result = (int *)malloc(sizeof(int) * stacks->a->count);
	if (result == NULL)
		error("error\n");
	head = stacks->a->head;
	while (i < stacks->a->count)
	{
		result[i] = stacks->a->head->number;
		stacks->a->head = stacks->a->head->next;
		i++;
	}
	stacks->a->head = head;
	stacks->arr = result;
	stacks->arr_count = stacks->a->count - 1;
}

static int	set_pivot(int	*arr, int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	pivot = arr[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && arr[low] <= pivot)
			low++;
		while (high >= left + 1 && arr[high] >= pivot)
			high--;
		if (low < high)
			swap(&arr[low], &arr[high]);
	}
	swap(&arr[left], &arr[high]);
	return (high);
}
