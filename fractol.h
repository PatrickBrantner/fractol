/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:20:48 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/24 22:15:33 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include<math.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include"./libft/libft.h"
# include"minilibx-linux/mlx.h"

# define WINDOW_WITH 400
# define WINDOW_HEIGHT 400
# define ITERATION 250

typedef struct s_data{
	void	*img;
	char	*addr;
	double	scale;
	double	pos_x;
	double	pos_y;
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	double	temp;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_main{
	void	*mlx_ptr;
	void	*mlx_win;
	int		switcher;
	int		zoom_level;
	double	zoom_factor;
	t_data	img;
	t_data	scale;
	t_data	pos_x;
	t_data	pos_y;
}	t_main;

typedef struct s_color{
	double	hue;
	double	saturation;
	double	lightness;
	double	c;
	double	x;
	double	m;
	double	r;
	double	g;
	double	b;
	int		red;
	int		green;
	int		blue;
	int		set_color;
}	t_color;

void	ft_pixel_put(t_data *data, int x, int y, int color);
int		ft_close(t_main *main);
int		ft_key(int keycode, t_main *main);
void	ft_mandelbrot(t_data *img);
void	ft_julia(t_data *img);
void	ft_new_window(t_main *main);
void	display_param(void);
void	check_input(int argc, char **argv);
void	which_julia(char **argv, t_main *main);
void	which_fractal(char **argv, t_main *main);
int		ft_get_iteration(t_data *img, int iterate, double shift_real);
void	ft_pixel_put(t_data *data, int x, int y, int color);
void	ft_color_sheme(t_color *color);
void	ft_set_color(t_data *img, int x, int y, double iteration);
void	ft_set_sheme_one(t_color *color);
void	ft_set_sheme_two(t_color *color);
void	ft_set_sheme_three(t_color *color);
void	ft_set_sheme_four(t_color *color);
void	ft_set_sheme_five(t_color *color);
void	ft_set_sheme_six(t_color *color);
int		mouse_hook(int mouse_hook, int x, int y, t_main *main);
void	ft_new_window(t_main *main);
void	ft_burning_ship(t_data *img);
int		ft_get_iteration_burning(t_data *img, int iterate, double shift_real);

#endif
