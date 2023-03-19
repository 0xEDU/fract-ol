/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/19 17:43:20 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static int	mandelbrot(t_fractol *fractol, double n_re, double n_im)
{
	double	x2;
	double	y2;
	double	temp;
	int		iter;

	x2 = 0;
	y2 = 0;
	iter = 0;
	(void)fractol;
	while (iter < fractol->max_iter)
	{
		temp = x2 * x2 - y2 * y2 + n_re;
		y2 = 2 * x2 * y2 + n_im;
		x2 = temp;
		if (x2 * x2 + y2 * y2 > 4)
			return (iter);
		iter++;
	}
	return (iter);
}

double	map_re(t_fractol *fractol, int x)
{
	double	range;

	range = fractol->max_re - fractol->min_re;
	return (fractol->min_re + (x * range) / WIDTH);
}

double	map_im(t_fractol *fractol, int y)
{
	double	range;

	range = fractol->max_im - fractol->min_im;
	return (fractol->min_im + (y * range) / HEIGHT);
}

void	fractal_to_image(t_fractol *fractol)
{
	double	x;
	double	y;
	int		iter;

	x = -1;
	iter = 0;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			iter = mandelbrot(fractol, map_re(fractol, x), map_im(fractol, y));
			if (iter == fractol->max_iter)
				mlx_pixel_draw(&fractol->img, x, y, 0x000000);
			else
				mlx_pixel_draw(&fractol->img, x, y, fractol->color * iter * iter);
		}
	}
}

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->min_re = -2.2;
	fractol->max_re = 1.0;
	fractol->min_im = -1.5;
	fractol->max_im =
		(fractol->max_re - fractol->min_re) * HEIGHT / WIDTH + fractol->min_im;
	fractol->max_iter = 100;
	fractol->color = 265;
}

int	render_image(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx.mlx, fractol->mlx.window);
	fractal_to_image(fractol);
	mlx_image_to_window(fractol, 0, 0);
//	mlx_destroy_image(fractol->mlx.mlx, fractol->img.img);
	return (1);
}

int	main(void)
{
	t_fractol	fractol;

	init_mandelbrot(&fractol);
	mlx_open_window(&fractol.mlx);
	mlx_create_image(&fractol);
	mlx_loop_window(&fractol);
	return (0);
}
