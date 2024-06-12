/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:23:57 by mku               #+#    #+#             */
/*   Updated: 2024/06/12 22:47:14 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_min_max(t_map *map, t_pos *pos)
{
	if (map->max_x < pos->x)
		map->max_x = pos->x;
	if (map->min_x > pos->x)
		map->min_x = pos->x;
	if (map->max_y < pos->y)
		map->max_y = pos->y;
	if (map->min_y > pos->y)
		map->min_y = pos->y;
}

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
		get_min_max(map, &map->pos[i]);
		i++;
	}
}
