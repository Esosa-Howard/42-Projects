/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:28:03 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 16:11:02 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	if (!fractal)
		return (0);
	if (argc >= 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot(fractal);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		julia_set(fractal, ft_atod(argv[2]), ft_atod(argv[3]));
	else if (argc >= 2 && !ft_strncmp(argv[1], "julia", 5))
	{
		perror("Possible parameters:c = 0.285 + 0.01, c = -0.8 + 0.156");
		free(fractal);
	}
	else
	{
		input_check(1);
		free(fractal);
	}
}

void	mandelbrot(t_fractol *mb)
{
	mb->type = 0;
	def_fractal(mb, 0, 0);
	mb->mlx = mlx_init();
	if (!mb->mlx)
		perror("mlx_init failed\n");
	mb->win = mlx_new_window(mb->mlx, WIDTH, HEIGHT, "Fractol Project");
	if (!mb->win)
	{
		perror("Window failed to open\n");
		free(mb);
	}
	mb->img.img = mlx_new_image(mb->mlx, WIDTH, HEIGHT);
	if (!mb->img.img)
	{
		perror("Image failed to load\n");
		free(mb);
	}
	mb->img.addr = mlx_get_data_addr(mb->img.img, &mb->img.bpp,
			&mb->img.line_length, &mb->img.endian);
	if (!mb->img.addr)
		perror("Address was not found\n");
	render_mandelbrot(mb);
	hook_calls(mb);
	mlx_loop(mb->mlx);
}

void	julia_set(t_fractol *js, double cr, double ci)
{
	js->type = 1;
	def_fractal(js, cr, ci);
	js->mlx = mlx_init();
	if (!js->mlx)
		perror("mlx_init failed\n");
	js->win = mlx_new_window(js->mlx, WIDTH, HEIGHT, "Fractol Project");
	if (!js->win)
	{
		perror("Window failed to open\n");
		return (free(js));
	}
	js->img.img = mlx_new_image(js->mlx, WIDTH, HEIGHT);
	if (!js->img.img)
	{
		perror("Image failed to load\n");
		return (free(js));
	}
	js->img.addr = mlx_get_data_addr(js->img.img, &js->img.bpp,
			&js->img.line_length, &js->img.endian);
	if (!js->img.addr)
		perror("Address was not found\n");
	render_julia(js);
	hook_calls(js);
	mlx_loop(js->mlx);
}

void	def_fractal(t_fractol *fractal, double cr, double ci)
{
	if (fractal->type == 0)
	{
		fractal->z.real = 0;
		fractal->z.imgy = 0;
		fractal->zoom = 1.0;
		fractal->of_set.real = -0.5;
		fractal->of_set.imgy = 0.0;
	}
	if (fractal->type == 1)
	{
		fractal->c.real = cr;
		fractal->c.imgy = ci;
		fractal->zoom = 1.0;
		fractal->of_set.real = -0.5;
		fractal->of_set.imgy = 0.0;
	}
}
