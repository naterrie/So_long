/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:34:28 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/16 18:59:32 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *file)
{
	t_mlx	mlx_test;
	t_img	img;
	int		y;
	int		x;

	y = 0;
	x = 0;
	mlx_test.map = mapset(file);
	set_placement(&mlx_test);
	img.height = 0;
	img.weight = 0;
	img.path = "image/brick.xpm";
	mlx_test.mlx = mlx_init();
	mlx_test.win = mlx_new_window(mlx_test.mlx, 640, 480, "so_long");
	mlx_key_hook(mlx_test.win, key_hook, &mlx_test);
	img.img = mlx_xpm_file_to_image(mlx_test.mlx, img.img, &img.weight, &img.height);
	mlx_put_image_to_window(mlx_test.mlx, mlx_test.win, img.img, x, y);
	mlx_loop(mlx_test.mlx);
	return (0);
}
