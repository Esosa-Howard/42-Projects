/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:45:25 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 15:32:57 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_fractal(t_fractol *f);

static int	key_functions(int keycode, t_fractol *f)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(f->mlx, f->img.img);
		mlx_destroy_window(f->mlx, f->win);
		free(f);
		exit (0);
	}
	else if (f->type == 1 && keycode == 109)
	{
		f->type = 0;
		mlx_destroy_image(f->mlx, f->img.img);
		def_fractal(f, 0, 0);
		change_fractal(f);
	}
	else if (keycode == 106 && f->type == 0)
	{
		f->type = 1;
		mlx_destroy_image(f->mlx, f->img.img);
		f->c.real = -0.7;
		f->c.imgy = 0.3;
		change_fractal(f);
	}
	return (0);
}

static int	win_close(t_fractol *f)
{
	if (!f)
		return (1);
	mlx_destroy_image(f->mlx, f->img.img);
	mlx_destroy_window(f->mlx, f->win);
	free(f);
	exit(0);
}

void	hook_calls(t_fractol *f)
{
	mlx_hook(f->win, KeyPress, KeyPressMask, key_functions, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, DestroyNotify, StructureNotifyMask, win_close, f);
}

static void	change_fractal(t_fractol *f)
{
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_length, &f->img.endian);
	if (f->type == 0)
		render_mandelbrot(f);
	else
		render_julia(f);
}
