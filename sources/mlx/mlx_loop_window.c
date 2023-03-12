/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:36:47 by edu               #+#    #+#             */
/*   Updated: 2023/03/12 15:38:01 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_loop_window(t_mlx *mlx)
{
	mlx_key_hook(mlx->window, &mlx_key_press_events, mlx);
	mlx_hook(mlx->window, 17, 0, mlx_click_press_events, mlx);
	mlx_loop(mlx->mlx);
}
