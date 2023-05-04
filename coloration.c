/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloration.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:10:29 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/24 21:38:18 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_color_sheme(t_color *color)
{
	if (color->hue < 60)
		ft_set_sheme_one(color);
	else if (color->hue < 120)
		ft_set_sheme_two(color);
	else if (color->hue < 180)
		ft_set_sheme_three(color);
	else if (color->hue < 240)
		ft_set_sheme_four(color);
	else if (color->hue < 300)
		ft_set_sheme_five(color);
	else
		ft_set_sheme_six(color);
}

void	ft_set_color(t_data *img, int x, int y, double iteration)
{
	t_color	color;

	color.hue = (iteration / 250.0) * 360.0;
	color.saturation = 1.0;
	color.lightness = 0.5 + (iteration / 500.0);
	color.c = (1 - fabs(2 * color.lightness -1)) * color.saturation;
	color.x = color.c * (1 - fabs(fmod(color.hue / 60.0, 2) - 1));
	color.m = color.lightness - color.c / 2;
	if (iteration >= 250)
	{
		ft_pixel_put(img, x, y, 0);
		return ;
	}
	else
		ft_color_sheme(&color);
	color.red = (color.r + color.m) * 255;
	color.green = (color.g + color.m) * 255;
	color.blue = (color.b + color.m) * 255;
	color.set_color = (color.red << 16) | (color.green << 8) | color.blue;
	ft_pixel_put(img, x, y, color.set_color);
}
