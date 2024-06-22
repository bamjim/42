/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:57:28 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 00:26:23 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
	int		length;

	data.map = &map;
	init(&data.param, &data);
	if (argc != 2)
		fdf_error("WRONG ARGUMENT");
	length = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][length], ".fdf", 4))
		fdf_error("NOT .fdf FILE");
	map_load(&map, argv[1], &data);
	mlx_key_hook(data.param.win, &key_press, &data);
	mlx_loop(data.param.mlx_ptr);
	return (0);
}
