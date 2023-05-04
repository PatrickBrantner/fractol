/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schemes_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:07 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/24 22:00:50 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_sheme_one(t_color *color)
{
	color->r = color->c;
	color->g = color->x;
	color->b = 0;
}

void	ft_set_sheme_two(t_color *color)
{
	color->r = color->x;
	color->g = color->c;
	color->b = 0;
}

void	ft_set_sheme_three(t_color *color)
{
	color->r = 0;
	color->g = color->c;
	color->b = color->x;
}
