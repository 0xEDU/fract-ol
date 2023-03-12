/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:36:24 by edu               #+#    #+#             */
/*   Updated: 2023/03/12 16:22:38 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol	fractol;

	mlx_open_window(&fractol.mlx);
	mlx_create_image(&fractol);
	mlx_put_image_to_window(fractol.mlx.mlx, fractol.mlx.window, fractol.img.img, 0, 0);
	mlx_loop_window(&fractol.mlx);
	return (0);
}
