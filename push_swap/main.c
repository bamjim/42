/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:59 by mku               #+#    #+#             */
/*   Updated: 2024/07/02 18:16:40 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stacks(t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		error(ERROR);
	//char *a = "7 49 61 97 -80 14 9 -17 41 1";
	set_stacks(&stacks);
	if (argc == 2)
		init_number_type2(&stacks, &argv[1]);
	else
		init_number_type1(&stacks, argv, argc);

	//sa(deque);
	quick_sort(&stacks);
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
	stacks->a_stack = a_stack;
	stacks->b_stack = b_stack;
}
