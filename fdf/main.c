/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:57:28 by mku               #+#    #+#             */
/*   Updated: 2024/06/18 20:25:10 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int trgb)
{
	return (trgb << 24 | trgb << 16 | trgb << 8);
}

void	init(t_param *param, t_data *data)
{
	param->width = 1920;
	param->height = 1080;
	param->mlx_ptr = mlx_init();
	param->win = mlx_new_window(param->mlx_ptr, \
	param->width, param->height, "FDF");
	data->img = mlx_new_image(param->mlx_ptr, \
	param->width, param->height);
	data->addr = mlx_get_data_addr(data->img, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	data->map->x_angle = 30;
	data->map->y_angle = 35;
	data->map->flag = 1;
	data->scale = 1.5f;
	data->map->move_x = 0;
	data->map->move_y = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	data.map = &map;
	init(&data.param, &data);
	char *s1 = "./maps/test_maps/";
	argv[1] = ft_strjoin(s1,argv[1]);
	map_load(&map, argv[1], &data);
	mlx_key_hook(data.param.win, &key_press, &data);
	mlx_loop(data.param.mlx_ptr);
	return (0);
}
