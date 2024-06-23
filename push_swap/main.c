/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:59 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 23:05:03 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	deque;

	if (argc < 2)
		error(ERROR);
	deque.count = 0;
	deque.head = NULL;
	deque.tail = NULL;
	if (argc == 2)
		init_number_type2(&deque,&(argv[1]));
	else
		init_number_type1(&deque, argv, argc);
}
