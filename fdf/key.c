/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:57:10 by mku               #+#    #+#             */
/*   Updated: 2024/06/15 23:12:30 by mku              ###   ########.fr       */
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
	if (keycode == KEY_Q)
	{
		draw(data->map, data);
	}
	return (0);
}