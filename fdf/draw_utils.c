/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:51:41 by mku               #+#    #+#             */
/*   Updated: 2024/06/19 21:05:06 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}

void	init_copy_pos(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_size)
	{
		map->pos[i].x = map->copy_pos[i].x;
		map->pos[i].y = map->copy_pos[i].y;
		map->pos[i].z = map->copy_pos[i].z;
		i++;
	}
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
