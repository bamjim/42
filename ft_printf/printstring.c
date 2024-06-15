/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:20 by mku               #+#    #+#             */
/*   Updated: 2024/04/22 15:41:03 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strlengh(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	printstring(const char *str, int *length)
{
	int	slength;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	slength = strlengh(str);
	write(1, str, slength);
	(*length) += slength;
}
