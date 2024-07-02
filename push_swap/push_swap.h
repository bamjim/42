/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:11:19 by mku               #+#    #+#             */
/*   Updated: 2024/07/02 18:28:15 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"
# include <unistd.h>
# include <stdio.h>

# define ERROR "Error\n"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
	t_deque	*a_stack;
	t_deque	*b_stack;
	int		*arr;
	int		arr_count;
}	t_stacks;

//init_number.c
void	init_number_type1(t_stacks *stacks, char **s, int argc);
void	init_number_type2(t_stacks *stacks, char **s);
//init_number_utils.c
int		ft_atoi(char *nptr);
int		ft_atoi_type2(char **nptr);
void	check_arg(char **s, int argc);
void	check_arg_type2(char *s);
//utils.c
void	error(char *error);
void	print_list(t_stacks *stacks);
void	set_head_tail(t_stacks *stacks);
//swap.c
void	sa(t_deque *a_stack);
void	sb(t_deque *b_stack);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
//swap2.c
void	ra(t_deque *a_stack);
void	rb(t_deque *a_stack);
void	rr(t_stacks *stacks);
void	rra(t_deque *a_stack);
void	rrb(t_deque *b_stack);
//swap3.c
void	rrr(t_stacks *stack);
//sort.c
void	quick_sort(t_stacks *stacks);
#endif