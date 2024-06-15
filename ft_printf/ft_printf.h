/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:38:01 by mku               #+#    #+#             */
/*   Updated: 2024/04/27 03:37:26 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	printchar(int arg, int *length);
void	printstring(const char *str, int *length);
void	printpointer(void *p, int *length);
void	printhexadecimal(unsigned long long p, int *length);
void	printinteger(int arg, int *length);
void	print_u_integer(unsigned int arg, int *length);
void	printhexlower(unsigned int p, int *length);
void	printhexupper(unsigned int p, int *length);
void	putnumber(int idx, int *length);
int		ft_printf(const char *str, ...);
int		searchflag(va_list *arglist, int *idx, const char *str);
void	printpercent(int *length);
int		strlengh(const char *str);

#endif
