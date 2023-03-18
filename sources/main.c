/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/18 20:42:56 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	main(void)
{
	t_fractol	fractol;

	mlx_open_window(&fractol.mlx);
	mlx_create_image(&fractol);
	mlx_image_to_window(&fractol, 0, 0);
	mlx_destroy_image(fractol.mlx.mlx, fractol.img.img);
	mlx_loop_window(&fractol.mlx);
	return (0);
}
