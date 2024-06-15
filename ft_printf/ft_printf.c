/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:05:28 by mku               #+#    #+#             */
/*   Updated: 2024/05/07 20:29:42 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printpercent(int *length)
{
	write(1, "%", 1);
	(*length)++;
}

int	searchflag(va_list *arglist, int *idx, const char *str)
{
	int	length;

	length = 0;
	if (str[*idx + 1] == 'c')
		printchar(va_arg(*arglist, int), &length);
	if (str[*idx + 1] == 's')
		printstring(va_arg(*arglist, char *), &length);
	if (str[*idx + 1] == 'p')
		printpointer(va_arg(*arglist, void *), &length);
	if (str[*idx + 1] == 'd')
		printinteger(va_arg(*arglist, int), &length);
	if (str[*idx + 1] == 'i')
		printinteger(va_arg(*arglist, int), &length);
	if (str[*idx + 1] == 'u')
		print_u_integer(va_arg(*arglist, unsigned int), &length);
	if (str[*idx + 1] == 'x')
		printhexlower(va_arg(*arglist, unsigned int), &length);
	if (str[*idx + 1] == 'X')
		printhexupper(va_arg(*arglist, unsigned int), &length);
	if (str[*idx + 1] == '%')
		printpercent(&length);
	(*idx)++;
	return (length);
}

int	find_flag(const char str)
{
	char	*flag;
	int		i;

	i = 0;
	flag = "cspdiuxX%";
	while (flag[i] != '\0')
	{
		if (flag[i] == str)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	int		idx;
	int		length;

	if (str == NULL)
		return (-1);
	va_start(arglist, str);
	length = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == '%' && find_flag(str[idx + 1]))
			length += searchflag(&arglist, &idx, str);
		else
		{
			write(1, &str[idx], 1);
			length++;
		}
		idx++;
	}
	va_end(arglist);
	return (length);
}
#include <stdio.h>

int main(void)
{
	char *s;
	int a,b;

	s = NULL;
	a = printf(s);
	b = ft_printf(s);

	printf("%d    %d",a,b);
}