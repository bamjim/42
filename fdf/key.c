/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:57:10 by mku               #+#    #+#             */
/*   Updated: 2024/06/18 20:47:28 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	angle_key(int keycode, t_data *data);
void	scale_key(int keycode, t_data *data);
void	move_key(int keycode, t_data *data);
void	o_key(int keycode, t_data *data);

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_D || keycode == KEY_A \
	|| keycode == KEY_W || keycode == KEY_S)
		angle_key(keycode, data);
	if (keycode == KEY_UP || keycode == KEY_DOWN \
	|| keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_CENTER)
		move_key(keycode, data);
	if (keycode == KEY_E || keycode == KEY_R)
		scale_key(keycode, data);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		o_key(keycode, data);
	if (keycode == KEY_Q)
	{
		copy_draw(data->map, data);
		return (0);
	}
	draw(data->map, data);
	return (0);
}

void	angle_key(int keycode, t_data *data)
{
	if (keycode == KEY_A)
		data->map->x_angle += 5;
	if (keycode == KEY_D)
		data->map->x_angle -= 5;
	if (keycode == KEY_W)
		data->map->y_angle -= 5;
	if (keycode == KEY_S)
		data->map->y_angle += 5;
}

void	scale_key(int keycode, t_data *data)
{
	if (keycode == KEY_E)
	{
		data->scale *= 1.1f;
		resize_draw(data->map, data);
	}
	if (keycode == KEY_R)
	{
		data->scale /= 1.1f;
		resize_draw(data->map, data);
	}
}

void	move_key(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->map->move_y -= 30;
	if (keycode == KEY_DOWN)
		data->map->move_y += 30;
	if (keycode == KEY_RIGHT)
		data->map->move_x += 30;
	if (keycode == KEY_LEFT)
		data->map->move_x -= 30;
	if (keycode == KEY_CENTER)
	{
		data->map->move_x = 0;
		data->map->move_y = 0;
	}
}

void	o_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->param.mlx_ptr, data->param.win);
		exit(0);
	}
}
