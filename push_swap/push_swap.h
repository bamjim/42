/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:11:19 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 20:40:16 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

# include "deque.h"
# include <unistd.h>

//init_number.c
void	init_number(t_deque *deque, char **s);
//init_number_utils.c
int	ft_atoi(char **nptr);

#endif