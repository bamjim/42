/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:49:22 by mku               #+#    #+#             */
/*   Updated: 2024/07/22 21:13:48 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort(int	*arr, int left, int right);
static int	set_pivot(int *arr, int left, int rigth);

void	sort(int	*arr, int left, int right)
{
	int	pivot;

	if (left > right)
		return ;
	pivot = set_pivot(arr, left, right);
	sort(arr, left, pivot -1);
	sort(arr, pivot + 1, right);
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
