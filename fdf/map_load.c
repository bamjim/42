/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:47:13 by mku               #+#    #+#             */
/*   Updated: 2024/06/12 22:48:19 by mku              ###   ########.fr       */
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

	i = 0;
	map->map_size = map->heigth * map->width;
	map->pos = (t_pos *)malloc(sizeof(t_pos) * map->map_size);
	if (map->pos == NULL)
		fdf_error("pos allocate error");
	while (i < map->map_size)
	{
		while (*content == '\n' || *content == ' ')
			content++;
		//map->pos[i].x = (i % map->width);
		//map->pos[i].y = (i / map->width);
		map->pos[i].x = ((i % map->width) - (map->width / 2)) * (WINDOW_X / SCALE / map->width);
		map->pos[i].y = ((i / map->width) - (map->heigth / 2)) * (WINDOW_Y / SCALE / map->heigth);
		map->pos[i].z = check_content_value(&content, &map->pos[i]);
		i++;
	}
}

void	map_load(t_map *map, char *dir)
{
	char	*content;

	map->heigth = 0;
	map->width = 0;
	map->max_x = INT_MIN;
	map->max_y = INT_MIN;
	map->min_x = INT_MAX;
	map->min_y = INT_MAX;
	content = map_set(dir);
	if (content == NULL)
		fdf_error("READ MAP ERROR");
	check_map_size(content, map);
	pos_init(content, map);
}
