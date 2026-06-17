/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_js.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:30:31 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 15:47:03 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_julia(t_fractol *js)
{
	iter_col(js);
	mlx_put_image_to_window(js->mlx, js->win, js->img.img, 0, 0);
}

int	iterate_js(t_fractol *js, double zr, double zi, int max_iter)
{
	double	bound;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		js->z.real = zr * zr - zi * zi + js->c.real;
		js->z.imgy = zr * zi + zr * zi + js->c.imgy;
		zr = js->z.real;
		zi = js->z.imgy;
		bound = js->z.real * js->z.real + js->z.imgy * js->z.imgy;
		if (bound > 4)
			break ;
		i++;
	}
	return (i);
}
