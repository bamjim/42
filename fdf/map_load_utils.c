/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:07:18 by mku               #+#    #+#             */
/*   Updated: 2024/06/15 22:10:24 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_map_error(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\0')
	{
		if (!ft_isdigit(content[i]) || !fdf_is_space(content[i]))
		{
			free(content);
			fdf_error("wrong map");
		}
		i++;
	}
}

int	get_color_value(char **nptr)
{
	int	result;
	int	i;

	i = 0;
	result = 0x0;
	while (ft_isdigit(**nptr) || ft_isalpha(**nptr))
	{
		if (**nptr >= 'A' && **nptr <= 'F')
			i = 10 + **nptr - 'A';
		else if (**nptr >= 'a' && **nptr <= 'f')
			i = 10 + **nptr - 'a';
		else
			i = **nptr - '0';
		result *= 16;
		result += i;
		(*nptr)++;
	}
	return (result);
}

int	check_content_value(char **nptr, t_pos *pos)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (**nptr == '-')
	{
		sign *= -1;
		(*nptr)++;
	}
	while (**nptr >= '0' && **nptr <= '9')
	{
		result = result * 10 + (**nptr - '0');
		(*nptr)++;
	}
	if (!ft_strncmp(*nptr, ",0x", 3) || !ft_strncmp(*nptr, ",0X", 3))
	{
		(*nptr) += 3;
		pos->color = get_color_value(nptr);
	}
	else
		pos->color = COLOR_WHITE;
	return (result * sign);
}
