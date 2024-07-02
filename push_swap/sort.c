/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:49:22 by mku               #+#    #+#             */
/*   Updated: 2024/07/02 18:23:14 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_arr(t_stacks *a_stack);
void	sort(int	*arr, int left, int right);
int		set_pivot(int *arr, int left, int rigth);
void	swap(int	*arr, int a, int b);

void	quick_sort(t_stacks *stacks)
{
	int	*arr;

	set_arr(stacks);
	sort(stacks->arr, 0, stacks->arr_count);
	for(int i = 0; i < stacks->a_stack->count; i++)
		printf("%d\n",stacks->arr[i]);
}

void	set_arr(t_stacks *stacks)
{
	int		*result;
	int		i;
	t_node	*head;

	i = 0;
	result = (int *)malloc(sizeof(int) * stacks->a_stack->count);
	if (result == NULL)
		error("error\n");
	head = stacks->a_stack->head;
	while (i < stacks->a_stack->count)
	{
		result[i] = stacks->a_stack->head->number;
		stacks->a_stack->head = stacks->a_stack->head->next;
		i++;
	}
	stacks->a_stack->head = head;
	stacks->arr = result;
	stacks->arr_count = stacks->a_stack->count - 1;
}

void	sort(int	*arr, int left, int right)
{
	int	pivot;

	if (left > right)
		return ;
	pivot = set_pivot(arr, left, right);
	sort(arr, left, pivot -1);
	sort(arr, pivot + 1, right);
}

int	set_pivot(int	*arr, int left, int right)
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
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return (high);
}

void	swap(int *arr, int a, int b)
{
	int	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
