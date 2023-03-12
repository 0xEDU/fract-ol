/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:53:37 by edu               #+#    #+#             */
/*   Updated: 2023/03/12 16:02:46 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_pixel_draw(t_image *image, int x, int y, int color)
{
	char	*dst;
	int		*pixel;
	int		y_map;
	int		x_map;

	if (x > image->limits.right || x < image->limits.left
		|| y < image->limits.bottom
		|| y > image->limits.top)
		return ;
	y_map = (image->limits.top - y) * image->line_length;
	x_map = (image->limits.right + x) * (image->bits_per_pixel / 8);
	dst = image->addr + y_map + x_map;
	pixel = (int *)dst;
	*pixel = color;
}
