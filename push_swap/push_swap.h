/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:11:19 by mku               #+#    #+#             */
/*   Updated: 2024/07/23 16:12:14 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list.h"
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ERROR "Error\n"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		*arr;
	int		arr_count;
}	t_stacks;

//init_number.c
void	init_number_type1(t_stacks *stacks, char **s, int argc);
void	init_number_type2(t_stacks *stacks, char **s);
void	set_rank(t_list *a);
void	check_dup(t_list *a);
void	check_dup2(int count, int *arr);
//init_number_utils.c
int		ft_atoi(char *nptr, int *i);
int		ft_atoi_type2(char **nptr);
void	check_arg(char **s, int argc);
void	check_arg_type2(char *s);
//utils.c
void	error(char *error);
void	print_list(t_stacks *stacks);
void	swap(int *a, int *b);
void	init_arr(int *arr, t_list *temp);
void	check(t_stacks *stacks);
//operator.c
void	sa(t_list *a_stack);
void	sb(t_list *b_stack);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
//operator2.c
void	ra(t_list *a_stack);
void	rb(t_list *a_stack);
void	rr(t_stacks *stacks);
void	rra(t_list *a_stack);
void	rrb(t_list *b_stack);
//operator3.c
void	rrr(t_stacks *stack);
//sort.c
void	sort(int	*arr, int left, int right);
//stack_sort.c
void	radix(t_stacks *stacks);
int		is_sorted(t_list *a);
//base_case.c
void	base_case_three(t_list *a);
void	base_case_five(t_stacks *stacks);
//base_case_utils.c
void	case_132(t_list *a);
void	case_231(t_list *a);
void	case_321(t_list *a);
void	case_312(t_list *a);
void	case_213(t_list *a);

#endif