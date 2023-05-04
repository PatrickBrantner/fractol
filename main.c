/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:20:22 by pbrantne          #+#    #+#             */
/*   Updated: 2023/02/24 21:35:23 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_main	main;

	check_input(argc, argv);
	main.img.scale = 1;
	main.img.pos_x = 0;
	main.img.pos_y = 0;
	main.zoom_level = 0;
	main.zoom_factor = 0.1;
	main.mlx_ptr = mlx_init();
	main.mlx_win = mlx_new_window
		(main.mlx_ptr, WINDOW_WITH, WINDOW_HEIGHT, "Fract-ol");
	main.img.img = mlx_new_image(main.mlx_ptr, WINDOW_WITH, WINDOW_HEIGHT);
	main.img.addr = mlx_get_data_addr(main.img.img, &main.img.bits_per_pixel,
			&main.img.line_length, &main.img.endian);
	which_fractal(argv, &main);
	mlx_put_image_to_window(main.mlx_ptr, main.mlx_win, main.img.img, 0, 0);
	mlx_mouse_hook(main.mlx_win, mouse_hook, &main);
	mlx_hook(main.mlx_win, 2, 1L << 0, ft_key, &main);
	mlx_hook(main.mlx_win, 17, 0, ft_close, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}
