/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:27 by edu               #+#    #+#             */
/*   Updated: 2023/03/19 19:34:01 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1000.00
# define HEIGHT 1000.00
# include <math.h>
# include <mlx.h>
# include <X11/keysym.h>
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
	float	max_im;
	float	min_im;
	float	max_re;
	float	min_re;
	int		color;
	int		max_iter;
	int		args;
	double	arg_re;
	double	arg_im;
}		t_fractol;

void	init_mandelbrot(t_fractol *fractol);
int		handle_input(int key, t_fractol *f);
/* Events */
double	map_re(t_fractol *fractol, int x);
double	map_im(t_fractol *fractol, int y);
int		mouse(int x, int y, t_fractol *f);
int		mouse_zoom(int key, int x, int y, t_fractol *f);
int		render_image(t_fractol *fractol);

/* MLX-related functions */
void	mlx_image_to_window(t_fractol *fractol, int x, int y);
void	mlx_open_window(t_mlx *mlx);
void	mlx_loop_window(t_fractol *fractol);
void	mlx_close_window(t_fractol *fractol);
int		mlx_key_press_events(int key_code, t_mlx *mlx);
int		mlx_click_press_events(t_mlx *mlx);
void	mlx_pixel_draw(t_image *image, int x, int y, int color);
void	mlx_create_image(t_fractol *fractol);
#endif
