/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:52 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 22:55:20 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_deque *deque);

void	init_number_type1(t_deque *deque, char **s, int argc)
{
	int	num;
	int	i;

	i = 1;
	check_arg(s, argc);
	while (i < argc)
	{
		num = ft_atoi(s[i]);
		push_back(deque, num);
		i++;
	}
	print(deque);
}

void	init_number_type2(t_deque *deque, char **s)
{
	int	num;
	char **temp;

	temp = s;
	check_arg_type2(*temp);
	while (**temp != '\0')
	{
		if (**temp == ' ')
			(*temp)++;
		num = ft_atoi_type2(temp);
		push_back(deque, num);
	}
	print(deque);
}
void	print(t_deque *deque)
{
	for(int i = 0 ;i < deque->count; i ++)
	{
		printf("[%d] %d\n",i, deque->head->number);
		deque->head = deque->head->next;
	}
}
