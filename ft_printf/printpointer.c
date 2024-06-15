/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:58 by mku               #+#    #+#             */
/*   Updated: 2024/04/22 15:41:25 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printpointer(void *p, int *length)
{
	unsigned long long	temp;

	temp = (unsigned long long)p;
	if (temp == 0)
	{
		write(1, "(nil)", 5);
		(*length) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*length) += 2;
	printhexadecimal(temp, length);
}

void	printhexadecimal(unsigned long long p, int *length)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (p >= 16)
	{
		printhexadecimal(p / 16, length);
		(*length)++;
		write(1, &hex[p % 16], 1);
	}
	else
	{
		(*length)++;
		write(1, &hex[p], 1);
	}
}
