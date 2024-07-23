/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:59 by mku               #+#    #+#             */
/*   Updated: 2024/07/23 15:54:06 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stacks(t_stacks *stacks);
static void	free_stacks(t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	set_stacks(&stacks);
	if (argc < 2)
		exit(0);
	if (argc == 2)
		init_number_type2(&stacks, &argv[1]);
	else
		init_number_type1(&stacks, argv, argc);
	if (stacks.a->count <= 3)
		base_case_three(stacks.a);
	else if (stacks.a->count <= 5)
		base_case_five(&stacks);
	else
		radix(&stacks);
	free_stacks(&stacks);
}

static void	set_stacks(t_stacks *stacks)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = (t_list *)malloc(sizeof(t_list));
	if (a_stack == NULL)
		error(ERROR);
	b_stack = (t_list *)malloc(sizeof(t_list));
	if (b_stack == NULL)
		error(ERROR);
	a_stack->count = 0;
	a_stack->head = NULL;
	a_stack->tail = NULL;
	b_stack->count = 0;
	b_stack->head = NULL;
	b_stack->tail = NULL;
	stacks->a = a_stack;
	stacks->b = b_stack;
}

static void	free_stacks(t_stacks *stacks)
{
	t_node	*temp;

	if (stacks->a->count == 1)
		free(stacks->a->head);
	else
	{
		while (stacks->a->head != NULL)
		{
			temp = stacks->a->head->next;
			free(stacks->a->head);
			stacks->a->head = temp;
		}
		while (stacks->b->head != NULL)
		{
			temp = stacks->b->head->next;
			free(stacks->b->head);
			stacks->b->head = temp;
		}
	}
	free(stacks->a);
	free(stacks->b);
}
