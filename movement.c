/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:26:51 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/13 17:28:03 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_collect(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	set_placement(t_mlx *mlx_test)
{
	while (mlx_test->map[mlx_test->y])
	{
		mlx_test->x = 0;
		while (mlx_test->map[mlx_test->y][mlx_test->x])
		{
			if (mlx_test->map[mlx_test->y][mlx_test->x] == 'P')
				return ;
			mlx_test->x++;
		}
		mlx_test->y++;
	}
}

int	player_position(t_mlx *mlx_test, int i, int j)
{
	static int	movement;

	mlx_test->y += i;
	mlx_test->x += j;
	if (mlx_test->y <= 0 || mlx_test->x <= 0 || \
		mlx_test->map[mlx_test->y][mlx_test->x] == '1')
	{
		mlx_test->y -= i;
		mlx_test->x -= j;
	}
	else
	{
		if (mlx_test->map[mlx_test->y][mlx_test->x] == 'C')
			mlx_test->map[mlx_test->y][mlx_test->x] = '0';
		if (mlx_test->map[mlx_test->y][mlx_test->x] == 'E' \
			&& exit_collect(mlx_test->map) == 0)
		{
			free(mlx_test->map);
			exit(0);
		}
		movement++;
	}
	printmap(mlx_test->map);
	return (0);
}

int	key_hook(int key, t_mlx *mlx_test)
{
	if (key == 13)
		player_position(mlx_test, -1, 0);
	if (key == 1)
		player_position(mlx_test, 1, 0);
	if (key == 0)
		player_position(mlx_test, 0, -1);
	if (key == 2)
		player_position(mlx_test, 0, 1);
	if (key == 53)
	{
		free (mlx_test->map);
		exit(0);
	}
	return (0);
}
