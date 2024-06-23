/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:59 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 20:56:12 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	deque;

	if (argc != 2)
	{
		write(1, "ERROR", 5);
		return ;
	}
	deque.count = 0;
	deque.head = NULL;
	deque.tail = NULL;
	init_number(&deque, &(argv[1]));
}