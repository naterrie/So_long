/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:26:51 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/18 18:06:07 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_mlx *mlx)
{
	free (mlx->map);
	exit(0);
}

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

void	set_placement(t_mlx *mlx)
{
	mlx->y = 0;
	while (mlx->map[mlx->y])
	{
		mlx->x = 0;
		while (mlx->map[mlx->y][mlx->x])
		{
			if (mlx->map[mlx->y][mlx->x] == 'P')
				return ;
			mlx->x++;
		}
		mlx->y++;
	}
}

int	player_position(t_mlx *mlx, int i, int j)
{
	static int	movement;

	mlx->y += i;
	mlx->x += j;
	if (mlx->y <= 0 || mlx->x <= 0 || \
		mlx->map[mlx->y][mlx->x] == '1')
	{
		mlx->y -= i;
		mlx->x -= j;
	}
	else
	{
		ft_putnbr(movement);
		write(1, "\n", 1);
		if (mlx->map[mlx->y][mlx->x] == 'C')
			mlx->map[mlx->y][mlx->x] = '0';
		if (mlx->map[mlx->y][mlx->x] == 'E' \
			&& exit_collect(mlx->map) == 0)
			ft_close(mlx);
		movement++;
	}
	return (0);
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == 13)
	{
		player_position(mlx, -1, 0);
		set_sprite(mlx, 2, -1, 0);
	}
	if (key == 1)
	{
		player_position(mlx, 1, 0);
		set_sprite(mlx, 2, 1, 0);
	}
	if (key == 0)
	{
		player_position(mlx, 0, -1);
		set_sprite(mlx, 2, 0, -1);
	}
	if (key == 2)
	{
		player_position(mlx, 0, 1);
		set_sprite(mlx, 2, 0, 1);
	}
	if (key == 53)
		ft_close(mlx);
	return (0);
}
