/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:19:03 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/24 21:30:04 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_new_window(t_main *main)
{
	if (main->switcher == 0)
		ft_mandelbrot(&(main->img));
	if (main->switcher == 1)
		ft_julia(&(main->img));
	if (main->switcher == 2)
		ft_burning_ship(&(main->img));
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, main->img.img, 0, 0);
}

int	ft_key(int keycode, t_main *main)
{
	double	step_size;

	step_size = 0.1 / main->img.scale;
	if (keycode == 65307)
		ft_close(main);
	else if (keycode == 65361)
		main->img.pos_x -= step_size;
	else if (keycode == 65364)
		main->img.pos_y -= step_size;
	else if (keycode == 65363)
		main->img.pos_x += step_size;
	else if (keycode == 65362)
		main->img.pos_y += step_size;
	ft_new_window(main);
	return (0);
}

int	ft_close(t_main *main)
{
	mlx_clear_window(main->mlx_ptr, main->mlx_win);
	mlx_destroy_image(main->mlx_ptr, main->img.img);
	mlx_destroy_window(main->mlx_ptr, main->mlx_win);
	mlx_destroy_display(main->mlx_ptr);
	mlx_loop_end(main->mlx_ptr);
	free(main->mlx_ptr);
	exit (0);
}

int	mouse_hook(int mouse_hook, int x, int y, t_main *main)
{
	(void)x;
	(void)y;
	if (mouse_hook == 4)
	{
		main->zoom_level += 1;
		main->img.scale = main->img.scale * (1 + main->zoom_factor);
	}
	else if (mouse_hook == 5)
	{
		main->zoom_level += 1;
		main->img.scale = main->img.scale * (1 - main->zoom_factor);
	}
	main->img.scale = main->img.scale;
	ft_new_window(main);
	return (0);
}
