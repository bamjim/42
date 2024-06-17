/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:23:57 by mku               #+#    #+#             */
/*   Updated: 2024/06/17 22:28:35 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map)
{
	double	pi;
	int		i;

	i = 0;
	pi = 3.1415926;
	while (i < map->map_size)
	{
		map->pos[i].x = (map->copy_pos[i].x * cos((map->x_angle * pi) / 180)) - \
		(map->copy_pos[i].y * sin((map->x_angle * pi) / 180));
		if (map->y_angle < 90 || map->y_angle > - 90)
			map->pos[i].y = (map->copy_pos[i].x * sin((map->y_angle * pi) / 180)) + \
			(map->copy_pos[i].y * sin((map->y_angle * pi) / 180) - map->pos[i].z);
		else
			map->pos[i].y = (map->copy_pos[i].x * sin((map->y_angle * pi) / 180)) + \
			(map->copy_pos[i].y * sin((map->y_angle * pi) / 180) + map->pos[i].z);
		i++;
	}
}
