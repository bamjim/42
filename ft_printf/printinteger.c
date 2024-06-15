/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:46:58 by mku               #+#    #+#             */
/*   Updated: 2024/04/22 15:40:41 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnumber(int temp, int *length)
{
	char	buf;

	buf = temp + '0';
	write(1, &buf, 1);
	(*length)++;
}

void	printinteger(int arg, int *length)
{
	long long	temp;

	temp = (long long)arg;
	if (temp < 0)
	{
		write(1, "-", 1);
		(*length)++;
		temp *= -1;
	}
	if (temp >= 10)
	{
		printinteger(temp / 10, length);
		putnumber(temp % 10, length);
	}
	else
		putnumber(temp, length);
}

void	print_u_integer(unsigned int arg, int *length)
{
	unsigned long long	temp;

	temp = (unsigned long long)arg;
	if (temp >= 10)
	{
		print_u_integer(temp / 10, length);
		putnumber(temp % 10, length);
	}
	else
	{
		putnumber(temp, length);
	}
}
