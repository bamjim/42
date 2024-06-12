/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:54:48 by mku               #+#    #+#             */
/*   Updated: 2024/06/12 22:46:02 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
