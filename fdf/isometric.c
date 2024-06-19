/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:23:57 by mku               #+#    #+#             */
/*   Updated: 2024/06/19 14:43:58 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map)
{
	double	pi;
	int		i;
	float	xa;
	float	ya;

	i = 0;
	pi = 3.1415926;
	xa = (map->x_angle * pi) / 180;
	ya = (map->y_angle * pi) / 180;
	while (i < map->map_size)
	{
		map->pos[i].x = (map->copy_pos[i].x * cos(xa)) - \
		(map->copy_pos[i].y * sin(xa));
		if (ya < 90 || ya > -90)
			map->pos[i].y = (map->copy_pos[i].x * sin(ya)) + \
			(map->copy_pos[i].y * sin(ya) - map->pos[i].z);
		else
			map->pos[i].y = (map->copy_pos[i].x * sin(ya)) + \
			(map->copy_pos[i].y * sin(ya) + map->pos[i].z);
		i++;
	}
}
