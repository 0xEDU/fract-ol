/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:05:53 by edu               #+#    #+#             */
/*   Updated: 2023/03/19 19:33:42 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	mlx_close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx.mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.window);
	mlx_destroy_display(fractol->mlx.mlx);
	if (fractol->mlx.mlx)
		free(fractol->mlx.mlx);
	exit(0);
}
