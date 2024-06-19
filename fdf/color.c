/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:16 by mku               #+#    #+#             */
/*   Updated: 2024/06/19 21:04:51 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	lerp(int start, int end, float t)
{
	return ((int)(start + t * (end - start)));
}

static int	get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

static int	get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

static int	get_b(int rgb)
{
	return (rgb & 0xFF);
}

int	gradiant(int color1, int color2, float slope)
{
	int	r;
	int	g;
	int	b;

	r = lerp(get_r(color1), get_r(color2), slope);
	g = lerp(get_g(color1), get_g(color2), slope);
	b = lerp(get_b(color1), get_b(color2), slope);
	return ((r << 16) | (g << 8) | b);
}
