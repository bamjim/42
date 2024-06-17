/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:57:10 by mku               #+#    #+#             */
/*   Updated: 2024/06/17 21:13:18 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_data *data)
{
	printf("key_code %d\n",keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->param.mlx_ptr, data->param.win);
		exit(0);
	}
	if (keycode == KEY_A) // a
		data->map->x_angle += 5;
	if (keycode == KEY_D) // d
		data->map->x_angle -= 5;
	if (keycode == KEY_W)
		data->map->y_angle -= 5;
	if (keycode == KEY_S)
		data->map->y_angle += 5;
	if (keycode == KEY_E)
	{
		data->scale *= 1.1f;
		printf("x_angle = %d y_angle = %d scale = %f\n",data->map->x_angle,data->map->y_angle,data->scale);
		resize_draw(data->map, data);
		return (0);
	}
	if (keycode == KEY_R)
	{
		data->scale /= 1.1f;
		printf("x_angle = %d y_angle = %d scale = %f\n",data->map->x_angle,data->map->y_angle,data->scale);
		resize_draw(data->map, data);
		return (0);
	}
	if (keycode == KEY_Q)
	{
		copy_draw(data->map, data);
		return (0);
	}
	printf("x_angle = %d y_angle = %d scale = %f\n",data->map->x_angle,data->map->y_angle,data->scale);
	draw(data->map, data);
	return (0);
}