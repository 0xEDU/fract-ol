/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_press_events.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:38:00 by edu               #+#    #+#             */
/*   Updated: 2023/03/19 18:40:25 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

// int	mlx_key_press_events(int key_code, t_mlx *mlx
// 
// 	if (key_code == 65307
// 		mlx_close_window(mlx)
// 	return (0)

void	arrows(int key, t_fractol *f)
{
	double	range_re;
	double	range_im;

	range_re = f->max_re - f->min_re;
	range_im = f->max_im - f->min_im;
	if (key == XK_Left)
	{
		f->min_re -= range_re * 0.1;
		f->max_re -= range_re * 0.1;
	}
	else if (key == XK_Right)
	{
		f->min_re += range_re * 0.1;
		f->max_re += range_re * 0.1;
	}
	else if (key == XK_Up)
	{
		f->min_im -= range_im * 0.1;
		f->max_im -= range_im * 0.1;
	}
	else if (key == XK_Down)
	{
		f->min_im += range_im * 0.1;
		f->max_im += range_im * 0.1;
	}
}

void	new_max_iter(int key, t_fractol *f)
{
	if (key == 'a')
		f->max_iter += 10;
	if (key == 'd')
		f->max_iter -= 10;
}

void	key_zoom(int key, t_fractol *f)
{
	double	range_re;
	double	range_im;

	range_re = f->max_re - f->min_re;
	range_im = f->max_im - f->min_im;
	if (key == 'z')
	{
		f->min_re += range_re * 0.1;
		f->max_re -= range_re * 0.1;
		f->min_im += range_im * 0.1;
		f->max_im -= range_im * 0.1;
	}
	else if (key == 'x')
	{
		f->min_re -= range_re * 0.1;
		f->max_re += range_re * 0.1;
		f->min_im -= range_im * 0.1;
		f->max_im += range_im * 0.1;
	}
}


int	handle_input(int key, t_fractol *f)
{
	if (key == XK_Escape)
		mlx_close_window(&f->mlx);
	else if (key == 114)
		init_mandelbrot(f);
	else if (key == 32)
	{
		if (f->color == 4)
			f->color = 0;
		else
			f->color++;
	}
	if (key == 'a' || key == 'd')
		new_max_iter(key, f);
	// else if (key == 's' && f->fractal == 2)
	// 	f->args = ft_invert(f->args);
	else if (key == 'z' || key == 'x')
		key_zoom(key, f);
	arrows(key, f);
	return (0);
}
