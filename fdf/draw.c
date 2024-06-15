/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:54:48 by mku               #+#    #+#             */
/*   Updated: 2024/06/15 23:11:19 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_map *map,t_data *data)
{
	isometric(map);
	pos_scale(map);
	draw_line(map, data);
	mlx_put_image_to_window(data->param.mlx_ptr, \
	data->param.win, data->img, 0, 0);
}

void	draw_line(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->map_size)
	{
		if ((i + 1 < map->map_size) && (i + 1) % map->width != 0)
			bresenham(&map->pos[i], &map->pos[i + 1], data);
		if (i + map->width < map->map_size)
			bresenham(&map->pos[i], &map->pos[i + map->width], data);
		i++;
	}
}

void	draw_copy_line(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->map_size)
	{
		if ((i + 1 < map->map_size) && (i + 1) % map->width != 0)
			bresenham(&map->copy_pos[i], &map->copy_pos[i + 1], data);
		if (i + map->width < map->map_size)
			bresenham(&map->copy_pos[i], &map->copy_pos[i + map->width], data);
		i++;
	}
}
