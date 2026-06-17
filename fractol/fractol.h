/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:28:06 by ahoward           #+#    #+#             */
/*   Updated: 2026/01/07 15:45:41 by ahoward          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "../../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800
# define ESC 65307

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		colr;
	int		endian;
}		t_img;

typedef struct s_complex
{
	double	real;
	double	imgy;
}		t_cmx;

typedef struct s_fractol
{
	int			type;
	void		*mlx;
	void		*win;
	t_img		img;
	t_cmx		z;
	t_cmx		c;
	t_cmx		of_set;
	double		zoom;
}		t_fractol;

void			input_check(int error_type);
void			def_fractal(t_fractol *fractal, double zr, double ci);
void			my_mlx_pixel_put(t_img *img, int x, int y, int colour);
void			mandelbrot(t_fractol *fractal);
void			render_mandelbrot(t_fractol *mb);
double			re_scale(double cord, double max, double a, double b);
void			render_mandelbrot(t_fractol *fractal);
void			iter_col(t_fractol *mb);
void			iter_row(t_fractol *mb, int y, int iter, int max_iter);
int				iterate_mb(t_fractol *mb, double cr, double ci, int max_iter);
unsigned int	smooth_colour(int iter, int max_iter);
void			hook_calls(t_fractol *f);
void			julia_set(t_fractol *js, double cr, double ci);
void			render_julia(t_fractol *julia);
int				iterate_js(t_fractol *js, double zr, double zi, int max_iter);
int				mouse_hook(int buttom, int x, int y, t_fractol *f);

#endif