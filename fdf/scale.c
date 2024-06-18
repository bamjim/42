/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:00:27 by mku               #+#    #+#             */
/*   Updated: 2024/06/18 19:50:15 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pos_scale(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_size)
	{
		map->pos[i].x += (WINDOW_X / 2) + map->move_x;
		map->pos[i].y += (WINDOW_Y / 2.1) + map->move_y;
		i++;
	}
}

void	set_z_scale(t_map *map, t_data *data)
{
	int	i;
	int	scale;

	i = 0;
	if (map->max_z == map->min_z)
		return ;
	scale = (int)(map->map_size / (map->max_z - map->min_z));
	if (map->max_z < 30 && map->min_z > -20 && scale < 165)
	{	
		while (i < map->map_size)
		{
			if ((WINDOW_Y / 1.7 / map->heigth) * 0.3 > map->max_z)
			{
				map->pos[i].z *= ((WINDOW_Y / data->scale / map->heigth) * 0.2) / 2;
				map->copy_pos[i].z *= ((WINDOW_Y / data->scale / map->heigth) * 0.2) / 2;
			}
			else
			{
				map->pos[i].z *= (WINDOW_Y / data->scale / map->heigth) * 0.2;
				map->copy_pos[i].z *= (WINDOW_Y / data->scale / map->heigth) * 0.2;
			}
			i++;
		}
	}
}

void	scale(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->map_size)
	{
		init_xyz(map, i, data);
		i++;
	}
}