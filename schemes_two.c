/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schemes_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:19 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/24 22:02:26 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_sheme_four(t_color *color)
{
	color->r = 0;
	color->g = color->x;
	color->b = color->c;
}

void	ft_set_sheme_five(t_color *color)
{
	color->r = color->x;
	color->g = 0;
	color->b = color->c;
}

void	ft_set_sheme_six(t_color *color)
{
	color->r = color->c;
	color->g = 0;
	color->b = color->x;
}
