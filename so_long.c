/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:34:28 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/13 16:30:31 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *file)
{
	t_mlx	mlx_test;
	char	*path_image;

	mlx_test.map = mapset(file);
	set_placement(&mlx_test);
	(void) file;
	path_image = "brick.png";
	mlx_test.mlx = mlx_init();
	mlx_test.win = mlx_new_window(mlx_test.mlx, 640, 480, "so_long");
	mlx_key_hook(mlx_test.win, key_hook, &mlx_test);
	mlx_loop(mlx_test.mlx);
	return (0);
}
