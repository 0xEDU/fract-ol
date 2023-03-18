/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:54:48 by edu               #+#    #+#             */
/*   Updated: 2023/03/18 20:37:15 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

/* mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y) */
void	mlx_image_to_window(t_fractol *fractol, int x, int y)
{
	mlx_put_image_to_window(
		fractol->mlx.mlx,
		fractol->mlx.window,
		fractol->img.img,
		x, y);
	mlx_destroy_image(fractol->mlx.mlx, fractol->img.img);
}
