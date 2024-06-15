/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:24:01 by mku               #+#    #+#             */
/*   Updated: 2024/06/15 22:09:29 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	hamham(t_ham *ham, t_pos *start, t_pos *end)
{
	ham->y = start->y;
	ham->x = start->x;
	ham->width = abs(end->x - start->x);
	ham->height = abs(end->y - start->y);
	if (end->y < start->y)
		ham->yfactor = -1;
	else
		ham->yfactor = 1;
	if (end->x < start->x)
		ham->xfactor = -1;
	else
		ham->xfactor = 1;
}

void	x_line(t_ham *ham, t_data *data, t_pos *start, t_pos *end)
{
	int	i;

	i = 0;
	ham->det = (2 * ham->height) - ham->width;
	while (i < ham->width)
	{
		if (ham->det < 0)
			ham->det += 2 * ham->height;
		else
		{
			ham->y += ham->yfactor;
			ham->det += (2 * ham->height - 2 * ham->width);
		}
		my_mlx_pixel_put(data, ham->x, ham->y, start->color);
		ham->x += ham->xfactor;
		i++;
	}
}

void	y_line(t_ham *ham, t_data *data, t_pos *start, t_pos *end)
{
	int	i;

	i = 0;
	ham->det2 = (2 * ham->width) - ham->height;
	while (i < ham->height)
	{
		if (ham->det2 < 0)
			ham->det2 += 2 * ham->width;
		else
		{
			ham->x += ham->xfactor;
			ham->det2 += (2 * ham->width - 2 * ham->height);
		}
		my_mlx_pixel_put(data, ham->x, ham->y, start->color);
		ham->y += ham->yfactor;
		i++;
	}
}

void	bresenham(t_pos *start, t_pos *end, t_data *data)
{
	t_ham	ham;

	hamham(&ham, start, end);
	if (ham.width > ham.height)
		x_line(&ham, data, start, end);
	else
		y_line(&ham, data, start, end);
}
