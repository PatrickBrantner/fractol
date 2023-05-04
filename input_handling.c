/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:56:29 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/25 00:12:53 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_param(void)
{
	ft_printf("Input is wrong\n");
	ft_printf("Valid Parameters are: Mandelbrot Julia Burning\n");
	ft_printf("One Arguments of type int ");
	ft_printf("1 2 3 (Only in Combination  with Julia)\n");
	exit (1);
}

void	check_input(int argc, char **argv)
{
	if (argc == 1 || argc >= 4)
		display_param();
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) != 0
		&& ft_strncmp(argv[1], "Julia", 6) != 0
		&& ft_strncmp(argv[1], "Burning", 8))
		display_param();
	else if (argc == 3 && (ft_strncmp(argv[1], "Mandelbrot", 11) == 0
			|| ft_strncmp(argv[1], "Burning", 8) == 0))
		display_param();
	else if (ft_strncmp(argv[1], "Julia", 6) == 0 && argc != 3)
		display_param();
	else if (ft_strncmp(argv[1], "Julia", 6) == 0
		&& (ft_strncmp(argv[2], "1", 2) != 0 && (ft_strncmp(argv[2], "2", 2)
				!= 0 && ft_strncmp(argv[2], "3", 2) != 0)))
		display_param();
}

void	which_julia(char **argv, t_main *main)
{
	if (argv[2][0] == '1')
	{
		main->img.c_real = 0.3;
		main->img.c_imag = -0.01;
		ft_julia(&main->img);
	}
	else if (argv[2][0] == '2')
	{
		main->img.c_real = 0;
		main->img.c_imag = 0.8;
		ft_julia(&main->img);
	}
	else if (argv[2][0] == '3')
	{
		main->img.c_real = 0;
		main->img.c_imag = 1;
		ft_julia(&main->img);
	}
}

void	which_fractal(char **argv, t_main *main)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	{
		main->switcher = 0;
		ft_mandelbrot(&main->img);
	}
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		main->switcher = 1;
		which_julia(argv, main);
	}
	else if (ft_strncmp(argv[1], "Burning", 8) == 0)
	{
		main->switcher = 2;
		main->img.pos_x = 0;
		main->img.pos_y = 0.5;
		ft_burning_ship(&main->img);
	}
}
