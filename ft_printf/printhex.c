/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:04:57 by mku               #+#    #+#             */
/*   Updated: 2024/04/27 03:37:25 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printhexlower(unsigned int p, int *length)
{
	const char		*hex;

	hex = "0123456789abcdef";
	if (p >= 16)
	{
		printhexlower(p / 16, length);
		write(1, &hex[p % 16], 1);
		(*length)++;
	}
	else
	{
		write(1, &hex[p], 1);
		(*length)++;
	}
}

void	printhexupper(unsigned int p, int *length)
{
	const char		*hex;

	hex = "0123456789ABCDEF";
	if (p >= 16)
	{
		printhexupper(p / 16, length);
		write(1, &hex[p % 16], 1);
		(*length)++;
	}
	else
	{
		write(1, &hex[p], 1);
		(*length)++;
	}
}
