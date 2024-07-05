/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:39:54 by mku               #+#    #+#             */
/*   Updated: 2024/07/05 18:42:44 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_deque *stack, int *pivot);
void	a_to_b(t_stacks *stacks);
void	b_to_a(t_stacks *stacks);
//void B_to_A(t_stacks *stack, int size);
//void A_to_B(t_stacks *stack, int size);


void	stack_sort(t_stacks *stacks)
{
	//A_to_B(stacks, stacks->a->count);
	a_to_b(stacks);
	b_to_a(stacks);
}

void	set_pivot(t_deque *stack, int *pivot)
{
	int	*arr;
	int	size;
	t_node	*temp;

	size = 0;
	temp = stack->head;
	arr = malloc(sizeof(int) * stack->count);
	if (arr == NULL)
		error("mallco error");
	if (stack->count == 2 && stack->head->number > stack->tail->number)
	{
		pivot[BIG] = stack->head->number;
		return ;
	}
	while (temp != NULL)
	{
		arr[size] = temp->number;
		temp = temp->next;
		size++;
	}
	sort(arr, 0, size);
	pivot[BIG] = arr[size / 2];
	free(arr);
	//pivot[SMALL] = arr[(size / 3) * 2];
	//if (pivot[BIG] < pivot[SMALL])
	//	swap(&pivot[BIG], &pivot[SMALL]);
}

void	a_to_b(t_stacks *stacks)
{
	int	pivot[2];
	int	i;
	int	size;

	size = stacks->a->count;
	i = 0;
	if (size <= 1)
		return ;
	set_pivot(stacks->a, pivot);
	while (i < size)
	{
		if (pivot[BIG] >= stacks->a->head->number)
			pb(stacks);
		else
			ra(stacks->a);
		//if (pivot[SMALL] >= stacks->b->head->number)
		//	rb(stacks->b);
		print_list(stacks);
		printf("-------%d--------\n",i);
		i++;
	}
	//a_to_b(stacks);
	b_to_a(stacks);
}

void	b_to_a(t_stacks *stacks)
{
	int	pivot[2];
	int	i;
	int	size;

	size = stacks->b->count;
	i = 0;
	if (size <= 1)
		return ;
	set_pivot(stacks->b, pivot);
	while (i < size)
	{
		if (pivot[BIG] <= stacks->b->head->number)
			pa(stacks);
		else
			rb(stacks->b);
		//if (pivot[SMALL] >= stacks->a->head->number)
		//	ra(stacks->b);
		print_list(stacks);
		printf("-------%d--------\n",i);
		i++;
	}
	//b_to_a(stacks);
	a_to_b(stacks);
}

//int find_pivot(t_deque *stack, int size)
//{
//	int		*ary;
//	int		pivot;
//	t_node	*temp;

//	ary = malloc(sizeof(int) * size);
//	temp = stack->head;

//	if (size == 1)
//		return (stack->head->number);
//	if (size == 2)
//		return (stack->head->number > stack->tail->number ? stack->tail->number : stack->head->number);

//	for (int i = 0; i < size; i++)
//	{
//		ary[i] = temp->number;
//		temp = temp->next;
//	}

//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size - i - 1; j++)
//		{
//			if (ary[j] > ary[j + 1])
//				swap(ary + j, ary + j + 1);
//		}
//	}
//	for(int i = 0;i < size; i ++)
//		printf("%d\n",ary[i]);
//	pivot = ary[size / 2];
//	free(ary);
//	return (pivot);
//}

//void A_to_B(t_stacks *stack, int size)
//{
//	int pivot;
//	int ra_cnt;
//	int pb_cnt;

//	ra_cnt = 0;
//	pb_cnt = 0;
//	if (size == 1)
//		return;
//	pivot = find_pivot(stack->a, size);
//	for (int i = 0; i < size; i++)
//	{
//		if (stack->a->head->number > pivot)
//		{
//			ra(stack->a);
//			ra_cnt++;
//		}
//		else
//		{
//			pb(stack);
//			pb_cnt++;
//		}
//	}
//	for (int i = 0; i < ra_cnt; i++)
//		rra(stack->a);
//	A_to_B(stack, ra_cnt);
//	B_to_A(stack, pb_cnt);
//}

//void B_to_A(t_stacks *stack, int size)
//{
//	int pivot;
//	int rb_cnt;
//	int pa_cnt;

//	rb_cnt = 0;
//	pa_cnt = 0;
//	if (size == 1)
//	{
//		pa(stack);
//		return ;
//	}
//	pivot = find_pivot(stack->b, size);
//	for (int i = 0; i < size; i++)
//	{
//		if (stack->b->head->number <= pivot)
//		{
//			rb(stack->a);
//			rb_cnt++;
//		}
//		else
//		{
//			pa(stack);
//			pa_cnt++;
//		}
//	}
//	for (int i = 0; i < rb_cnt ; i++)
//		rrb(stack->b);
//	A_to_B(stack, pa_cnt);
//	B_to_A(stack, rb_cnt);
//}