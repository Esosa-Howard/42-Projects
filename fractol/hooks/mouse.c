/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:33:36 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 14:20:47 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_from(int x, int y, t_fractol *f)
{
	double	nx;
	double	ny;
	double	ox;
	double	oy;
	double	new_zoom;

	new_zoom = f->zoom * 1.05;
	oy = re_scale(y, HEIGHT, 2, -2) * f->zoom + f->of_set.imgy;
	ox = re_scale(x, WIDTH, -2, 2) * f->zoom + f->of_set.real;
	ny = re_scale(y, HEIGHT, 2, -2) * new_zoom + f->of_set.imgy;
	nx = re_scale(x, WIDTH, -2, 2) * new_zoom + f->of_set.real;
	f->of_set.real += ox - nx;
	f->of_set.imgy += oy - ny;
	f->zoom = new_zoom;
}

static void	zoom_at(int x, int y, t_fractol *f)
{
	double	nx;
	double	ny;
	double	ox;
	double	oy;
	double	new_zoom;

	new_zoom = f->zoom * 0.95;
	oy = re_scale(y, HEIGHT, 2, -2) * f->zoom + f->of_set.imgy;
	ox = re_scale(x, WIDTH, -2, 2) * f->zoom + f->of_set.real;
	ny = re_scale(y, HEIGHT, 2, -2) * new_zoom + f->of_set.imgy;
	nx = re_scale(x, WIDTH, -2, 2) * new_zoom + f->of_set.real;
	f->of_set.real += ox - nx;
	f->of_set.imgy += oy - ny;
	f->zoom = new_zoom;
}

int	mouse_hook(int buttom, int x, int y, t_fractol *f)
{
	if (buttom == 4)
		zoom_at(x, y, f);
	else if (buttom == 5)
		zoom_from(x, y, f);
	if (f->type == 1)
		render_julia(f);
	if (f->type == 0)
		render_mandelbrot(f);
	return (0);
}
