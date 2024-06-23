/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:11:19 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 23:04:36 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

# include "deque.h"
# include <unistd.h>
# include <stdio.h>

# define ERROR "ERROR"
//init_number.c
void	init_number_type1(t_deque *deque, char **s, int argc);
void	init_number_type2(t_deque *deque, char **s);
//init_number_utils.c
int	ft_atoi(char *nptr);
int	ft_atoi_type2(char **nptr);
void	check_arg(char **s, int argc);
void	check_arg_type2(char *s);
//utils.c
void	error(char *error);
#endif