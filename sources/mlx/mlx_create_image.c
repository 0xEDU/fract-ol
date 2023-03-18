/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:08:33 by edu               #+#    #+#             */
/*   Updated: 2023/03/18 20:04:57 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_create_image(t_fractol *fractol)
{
	fractol->img.img = mlx_new_image(fractol->mlx.mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
	fractol->img.limits.top = HEIGHT / 2;
	fractol->img.limits.bottom = -(HEIGHT / 2);
	fractol->img.limits.left = -(WIDTH / 2);
	fractol->img.limits.right = WIDTH / 2;
}
