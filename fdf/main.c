/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:57:28 by mku               #+#    #+#             */
/*   Updated: 2024/06/15 18:24:36 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int trgb)
{
	return (trgb << 24 | trgb << 16 | trgb << 8);
}

int	key_input(int key, t_param *param, t_pos *pos)
{
	printf("a");
	return (0);
}

void	set_mlx(t_param *param, t_data *data)
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
}

int	main(int argc, char **argv)
{
	t_param	param;
	t_data	data;
	t_map	map;

	data.map = &map;
	set_mlx(&param, &data);
	//char *s1 = "./maps/test_maps/";
	//argv[1] = ft_strjoin(s1,argv[1]);
	//map_load(&map, argv[1]);
	map_load(&map, "./maps/test_maps/42.fdf");
	isometric(&map);
	pos_scale(&map);
	draw_line(&map, &data);
	mlx_hook(param.win, 2, 1L << 0, &key_input, &param);
	mlx_put_image_to_window(param.mlx_ptr, param.win, data.img, 0, 0);
	mlx_loop(param.mlx_ptr);
	return (0);
}