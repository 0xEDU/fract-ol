/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:36:47 by edu               #+#    #+#             */
/*   Updated: 2023/03/19 19:26:02 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_loop_window(t_fractol *fractol)
{
	mlx_loop_hook(fractol->mlx.mlx, &render_image, fractol);
	mlx_key_hook(fractol->mlx.window, &handle_input, fractol);
	mlx_hook(fractol->mlx.window, 17, 0, mlx_click_press_events, &fractol->mlx);
	mlx_hook(fractol->mlx.window, 6, 1L << 6, &mouse, fractol);
	mlx_hook(fractol->mlx.window, 4, 1L << 2, &mouse_zoom, fractol);
	mlx_loop(fractol->mlx.mlx);
}
