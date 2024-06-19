/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:54:48 by mku               #+#    #+#             */
/*   Updated: 2024/06/19 21:26:36 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_map *map, t_data *data)
{
	ft_memset(data->addr, 0, (data->line_length * WINDOW_Y));
	isometric(map);
	pos_scale(map);
	draw_line(map, data);
	mlx_put_image_to_window(data->param.mlx_ptr, \
	data->param.win, data->img, 0, 0);
}

void	copy_draw(t_map *map, t_data *data)
{
	ft_memset(data->addr, 0, (data->line_length * WINDOW_Y));
	init_copy_pos(map);
	pos_scale(map);
	draw_line(map, data);
	mlx_put_image_to_window(data->param.mlx_ptr, \
	data->param.win, data->img, 0, 0);
}

void	resize_draw(t_map *map, t_data *data)
{
	ft_memset(data->addr, 0, (data->line_length * WINDOW_Y));
	scale(map, data);
	isometric(map);
	pos_scale(map);
	draw_line(map, data);
	mlx_put_image_to_window(data->param.mlx_ptr, \
	data->param.win, data->img, 0, 0);
}
