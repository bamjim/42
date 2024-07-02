/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:50:52 by mku               #+#    #+#             */
/*   Updated: 2024/07/02 18:25:24 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_number_type1(t_stacks *stacks, char **s, int argc)
{
	int	num;
	int	i;

	i = 1;
	check_arg(s, argc);
	while (i < argc)
	{
		num = ft_atoi(s[i]);
		push_back(stacks->a_stack, num);
		i++;
	}
}

void	init_number_type2(t_stacks *stacks, char **s)
{
	int		num;
	char	**temp;

	temp = s;
	check_arg_type2(*s);
	while (**temp != '\0')
	{
		if (**temp == ' ')
			(*temp)++;
		else
		{
			num = ft_atoi_type2(temp);
			push_back(stacks->a_stack, num);
		}
	}
}
