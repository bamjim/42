/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:56:31 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 23:06:10 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_isdigit(int c);

int	ft_atoi(char *nptr)
{
	int		sign;
	long long	result;

	sign = 1;
	result = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int	ft_atoi_type2(char **nptr)
{
	int		sign;
	long long	result;

	sign = 1;
	result = 0;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign *= -1;
		(*nptr)++;
	}
	while (ft_isdigit(**nptr) && **nptr != '\0')
	{
		result = result * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	check_arg(char **s, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (!ft_isdigit(s[i][j]) && s[i][j] != '-' && s[i][j] != ' ')
				error(ERROR);
			j++;
		}
		i++;
	}
}

void	check_arg_type2(char *s)
{
	while (*s != '\0')
	{
		if (!ft_isdigit(*s) && *s != '-' && *s != ' ')
			error(ERROR);
		s++;
	}
}