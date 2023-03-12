/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:27 by edu               #+#    #+#             */
/*   Updated: 2023/03/12 16:24:09 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 600
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libput.h"

typedef struct s_mlx {
	void	*mlx;
	void	*window;
}				t_mlx;

typedef struct s_limits {
	int	top;
	int	bottom;
	int	left;
	int	right;
}				t_limits;

typedef struct s_image {
	t_limits	limits;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_fractol {
	t_mlx	mlx;
	t_image	img;
}		t_fractol;

/* MLX-related functions */
void	mlx_open_window(t_mlx *mlx);
void	mlx_loop_window(t_mlx *mlx);
void	mlx_close_window(t_mlx *mlx);
int		mlx_key_press_events(int key_code, t_mlx *mlx);
int		mlx_click_press_events(t_mlx *mlx);
void	mlx_pixel_draw(t_image *image, int x, int y, int color);
void	mlx_create_image(t_fractol *fractol);
#endif
