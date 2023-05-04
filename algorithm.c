/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:52:05 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/25 00:10:22 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_iteration(t_data *img, int iterate, double shift_real)
{
	while (iterate <= ITERATION)
	{
		img->temp = img->z_real;
		img->z_real = img->z_real * img->z_real
			- img->z_imag * img->z_imag + img->c_real - shift_real;
		img->z_imag = 2 * img->temp * img->z_imag + img->c_imag;
		if (img->z_real * img->z_real + img->z_imag * img->z_imag > 4)
			break ;
		iterate++;
	}
	return (iterate);
}

int	ft_get_iteration_burning(t_data *img, int iterate, double shift_real)
{
	while (iterate <= ITERATION)
	{
		img->temp = img->z_real;
		img->z_real = img->z_real * img->z_real
			- img->z_imag * img->z_imag + img->c_real - shift_real;
		img->z_imag = 2 * fabs(img->temp * img->z_imag) + img->c_imag;
		if (img->z_real * img->z_real + img->z_imag * img->z_imag > 4)
			break ;
		iterate++;
	}
	return (iterate);
}

void	ft_mandelbrot(t_data *img)
{
	int	x;
	int	y;
	int	iterate;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WITH)
		{
			img->c_real = ((200 - x) / (-150 * img->scale)) + img->pos_x;
			img->c_imag = (200 - y) / (150 * img->scale) + img->pos_y;
			img->z_real = 0;
			img->z_imag = 0;
			iterate = ft_get_iteration(img, 0, 0.8);
			ft_set_color(img, x, y, iterate);
			x++;
		}
		y++;
	}
}

void	ft_julia(t_data *img)
{
	int	x;
	int	y;
	int	iterate;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WITH)
		{
			img->z_real = ((200 - x) / (-150 * img->scale)) + img->pos_x;
			img->z_imag = (200 - y) / (150 * img->scale) + img->pos_y;
			iterate = ft_get_iteration(img, 0, 0);
			ft_set_color(img, x, y, iterate);
			x++;
		}
		y++;
	}
}

void	ft_burning_ship(t_data *img)
{
	int	x;
	int	y;
	int	iterate;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WITH)
		{
			img->c_real = ((200 - x) / (-150 * img->scale)) + img->pos_x;
			img->c_imag = -((200 - y) / (150 * img->scale) + img->pos_y);
			img->z_real = 0;
			img->z_imag = 0;
			iterate = ft_get_iteration_burning(img, 0, 0.5);
			ft_set_color(img, x, y, iterate);
			x++;
		}
		y++;
	}
}
