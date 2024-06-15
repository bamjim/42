/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:47:13 by mku               #+#    #+#             */
/*   Updated: 2024/06/15 18:43:32 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

void	check_map_size(char *content, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (*content != '\0')
	{
		if (*content != ' ' && *content != '\n' && fdf_is_space(*(content + 1)))
			x++;
		if (*content == '\n' || *(content + 1) == '\0')
		{
			if (map->width == 0)
				map->width = x;
			if ((map->width != x && map->width != 0) || x == 0)
				fdf_error("MAP SIZE ERROR");
			x = 0;
			y++;
		}
		content++;
	}
	map->heigth = y;
}


void	pos_init(char *content, t_map *map)
{
	int		i;
	int		z;
	
	i = 0;
	map->map_size = map->heigth * map->width;
	map->pos = (t_pos *)malloc(sizeof(t_pos) * map->map_size);
	if (map->pos == NULL)
		fdf_error("pos allocate error");
	while (i < map->map_size)
	{
		while (*content == '\n' || *content == ' ')
			content++;
		map->pos[i].x = ((i % map->width) - (map->width / 2)) * (WINDOW_X / SCALE / map->width);
		map->pos[i].y = ((i / map->width) - (map->heigth / 2)) * (WINDOW_Y / SCALE / map->heigth);
		z = check_content_value(&content, &map->pos[i]);
		if (z > map->max_z)
			map->max_z = z;
		else if (z < map->min_z)
			map->min_z = z;
		map->pos[i].z = z;
		i++;
	}
}

void	set_z_scale(t_map *map)
{
	int	i;
	int	scale;

	i = 0;
	scale = map->map_size / (map->max_z - map->min_z);
	while (i < map->map_size)
	{
		if (map->pos[i].z >= 0 && map->max_z > 30)
			map->pos[i].z *= 30 / map->max_z;
		else if (map->pos[i].z < 0 && map->min_z < -20)
			map->pos[i].z *= -20 / map->min_z;
		i++;
	}
}

void	map_load(t_map *map, char *dir)
{
	char	*content;

	map->heigth = 0;
	map->width = 0;
	map->max_z = -1;
	map->min_z = 1;
	content = map_set(dir);
	if (content == NULL)
		fdf_error("READ MAP ERROR");
	check_map_size(content, map);
	pos_init(content, map);
	set_z_scale(map);
}
