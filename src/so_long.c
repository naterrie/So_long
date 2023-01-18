/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:34:28 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/18 14:50:31 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *file)
{
	t_mlx	mlx;
	int		window_lenght;
	int		window_weight;

	mlx.map = mapset(file);
	window_weight = 0;
	while (mlx.map[window_weight])
		window_weight++;
	window_weight = window_weight * 64;
	window_lenght = (ft_strlen(mlx.map[0]) - 1) * 64;
	set_placement(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, window_lenght, window_weight, "so_long");
	print_map(mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
