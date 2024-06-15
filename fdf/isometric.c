/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:23:57 by mku               #+#    #+#             */
/*   Updated: 2024/06/15 17:17:17 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map)
{
	double	pi;
	int		x_angle;
	int		y_angle;
	int		i;

	i = 0;
	pi = 3.1415926;
	x_angle = 35;
	y_angle = 40;
	while (i < map->map_size)
	{
		map->pos[i].x = (map->pos[i].x * cos(x_angle * pi / 180)) - \
		(map->pos[i].y * sin(x_angle * pi / 180));
		map->pos[i].y = (map->pos[i].x * sin(y_angle * pi / 180)) + \
		(map->pos[i].y * sin(y_angle * pi / 180) - map->pos[i].z);
		i++;
	}
}
