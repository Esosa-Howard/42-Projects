/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:05 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 14:10:16 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_fractol *mb)
{
	iter_col(mb);
	mlx_put_image_to_window(mb->mlx, mb->win, mb->img.img, 0, 0);
}

int	iterate_mb(t_fractol *mb, double cr, double ci, int max_iter)
{
	int		i;
	double	bound;
	double	zr;
	double	zi;

	mb->z.real = 0;
	mb->z.imgy = 0;
	i = 0;
	while (i < max_iter)
	{
		zr = mb->z.real;
		zi = mb->z.imgy;
		mb->z.real = zr * zr - zi * zi + cr;
		mb->z.imgy = zr * zi + zr * zi + ci;
		bound = mb->z.real * mb->z.real + mb->z.imgy * mb->z.imgy;
		if (bound > 4)
			break ;
		i++;
	}
	return (i);
}
