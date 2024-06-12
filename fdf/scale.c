/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:00:27 by mku               #+#    #+#             */
/*   Updated: 2024/06/12 21:24:39 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pos_scale(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_size)
	{
		map->pos[i].x += (WINDOW_X / 2);
		map->pos[i].y += (WINDOW_Y / 2);
		if (map->pos[i].z <= 10)
			map->pos[i].z = 0xFFBBFF;
		else if (map->pos[i].z <= 5)
			map->pos[i].z = 0x00FF00;
		i++;
	}
}

