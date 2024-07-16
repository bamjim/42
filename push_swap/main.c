/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:59 by mku               #+#    #+#             */
/*   Updated: 2024/07/16 19:38:22 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stacks(t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	//if (argc < 2)
	//	error(ERROR);
	//char *a = "7 49 9 97 -80 14 61 -17 41 1 100";
	char *a = "7 4 7";
	set_stacks(&stacks);
	//if (argc == 2)
		init_number_type2(&stacks, &a);
	//else
	//	init_number_type1(&stacks, argv, argc);


	if (stacks.a->count <= 3)
		base_case_sort(stacks.a);
	else
		greedy(&stacks);
}

static void	set_stacks(t_stacks *stacks)
{
	t_deque	*a_stack;
	t_deque	*b_stack;

	a_stack = (t_deque *)malloc(sizeof(t_deque));
	if (a_stack == NULL)
		error("ERROR");
	b_stack = (t_deque *)malloc(sizeof(t_deque));
	if (b_stack == NULL)
		error("ERROR");
	a_stack->count = 0;
	a_stack->head = NULL;
	a_stack->tail = NULL;
	b_stack->count = 0;
	b_stack->head = NULL;
	b_stack->tail = NULL;
	stacks->a = a_stack;
	stacks->b = b_stack;
}
