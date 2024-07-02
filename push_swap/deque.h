/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:33:15 by mku               #+#    #+#             */
/*   Updated: 2024/07/02 18:27:28 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				number;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_deque;

void	push_back(t_deque *deque, int number);
void	push_front(t_deque *deque, int number);
int		pop_back(t_deque *deque);
int		pop_front(t_deque *deque);

#endif