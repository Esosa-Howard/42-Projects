/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:42:11 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 15:51:13 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	first_fractal(int x, int y, t_fractol *f);
static void	second_fractal(int x, int y, t_fractol *f);

void	iter_col(t_fractol *f)
{
	int	y;
	int	iter;
	int	max_iter;

	y = 0;
	iter = 0;
	max_iter = 156;
	while (y < HEIGHT)
	{
		iter_row(f, y, iter, max_iter);
		y++;
	}
}

void	iter_row(t_fractol *f, int y, int iter, int max_iter)
{
	int				x;
	unsigned int	colour;

	x = 0;
	while (x < WIDTH)
	{
		if (f->type == 0)
		{
			first_fractal(x, y, f);
			iter = iterate_mb(f, f->c.real, f->c.imgy, max_iter);
		}
		else
		{
			second_fractal(x, y, f);
			iter = iterate_js(f, f->z.real, f->z.imgy, max_iter);
		}
		if (iter == max_iter)
			my_mlx_pixel_put(&f->img, x, y, 0x000000);
		else if (iter < max_iter)
		{
			colour = smooth_colour(iter, max_iter);
			my_mlx_pixel_put(&f->img, x, y, colour);
		}
		x++;
	}
}

static void	first_fractal(int x, int y, t_fractol *f)
{
	f->c.imgy = re_scale(y, HEIGHT, 2, -2) * f->zoom + f->of_set.imgy;
	f->c.real = re_scale(x, WIDTH, -2, 2) * f->zoom + f->of_set.real;
}

static void	second_fractal(int x, int y, t_fractol *f)
{
	f->z.imgy = re_scale(y, HEIGHT, 2, -2) * f->zoom + f->of_set.imgy;
	f->z.real = re_scale(x, WIDTH, -2, 2) * f->zoom + f->of_set.real;
}
