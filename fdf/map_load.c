/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:47:13 by mku               #+#    #+#             */
/*   Updated: 2024/06/19 21:09:01 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	zmaxmin(t_map *map, t_pos *pos, int z)
{
	if (z > map->max_z)
		map->max_z = z;
	else if (z < map->min_z)
		map->min_z = z;
	pos->z = z;
}

void	init_xyz(t_map *map, int i, t_data *data)
{
	int	z;

	map->pos[i].x = ((i % map->width) - (map->width / 2)) \
	* (WINDOW_Y / data->scale / map->width);
	map->pos[i].y = ((i / map->width) - (map->heigth / 2)) \
	* (WINDOW_Y / data->scale / map->width);
	map->copy_pos[i].x = ((i % map->width) - (map->width / 2)) \
	* (WINDOW_Y / data->scale / map->width);
	map->copy_pos[i].y = ((i / map->width) - (map->heigth / 2)) \
	* (WINDOW_Y / data->scale / map->width);
}

void	pos_init(char *content, t_map *map, t_data *data)
{
	int		i;
	int		z;

	i = 0;
	map->map_size = map->heigth * map->width;
	map->pos = (t_pos *)malloc(sizeof(t_pos) * map->map_size);
	if (map->pos == NULL)
		fdf_error("POS ALLOCATE ERROR");
	map->copy_pos = (t_pos *)malloc(sizeof(t_pos) * map->map_size);
	if (map->pos == NULL)
		fdf_error("COPY POS ALLOCATE ERROR");
	while (i < map->map_size)
	{
		while (*content == '\n' || *content == ' ')
			content++;
		init_xyz(map, i, data);
		z = check_content_value(&content, &map->pos[i]);
		zmaxmin(map, &(map->pos[i]), z);
		zmaxmin(map, &(map->copy_pos[i]), z);
		i++;
	}
}

void	map_load(t_map *map, char *dir, t_data *data)
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
	pos_init(content, map, data);
	set_z_scale(map, data);
}
