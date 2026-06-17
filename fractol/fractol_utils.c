/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:28:09 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 15:55:37 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	re_scale(double cord, double max, double a, double b)
{
	double	x;
	double	min;

	min = 0;
	x = a + (cord - min) * (b - a) / max - min;
	return (x);
}

void	input_check(int error_type)
{
	if (error_type == 1)
		perror("Write mandelbrot or Julia(with desired parameters)\n");
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

static unsigned int	blend(unsigned int col1, unsigned int col2, double t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (int)((1 - t) * ((col1 >> 16) & 0xFF) + t
			* ((col2 >> 16) & 0xFF)) & 0XFF;
	g = (int)((1 - t) * ((col1 >> 8) & 0xFF) + t * ((col2 >> 8) & 0xFF)) & 0XFF;
	b = (int)((1 - t) * (col1 & 0xFF) + t * ((col2) & 0xFF)) & 0XFF;
	return ((r << 16) | (g << 8) | b);
}

unsigned int	smooth_colour(int iter, int max_iter)
{
	unsigned int	green;
	unsigned int	blue;
	unsigned int	red;
	double			depth;

	green = 0xFF00FF00;
	red = 0xFFFF0000;
	blue = 0xFF0000FF;
	depth = re_scale((double)iter, (double)max_iter, 0, 1);
	return (blend(blue, green, depth));
}
