/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:25:39 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/25 16:02:17 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_position_on_map(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x] == 'E' && exit_collect(mlx->map) == 0)
	{
		write (1, "Congratulation ! You finished the map !\n", 40);
		ft_close(mlx);
	}
}

void	check_collision(t_mlx *mlx, int y, int x)
{
	if (mlx->y == y && mlx->x == x)
	{
		write (1, "Ho no, you've encountered a mob and he killed you !\n", 51);
		ft_close(mlx);
	}
}

void	mob_move(t_mlx *m, int y, int x)
{
	static int	n;

	n++;
	if (n % 2 == 0 && m->map[y][x + 1] == '0' && check_player(m, y, x + 1) == 0)
	{
		mlx_put_image_to_window(m->mlx, m->win, m->i.mob.img, \
								(x + 1) * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, m->i.floor.img, \
								x * 32, y * 32);
		m->map[y][x + 1] = 'M';
		m->map[y][x] = '0';
		check_collision(m, y, x + 1);
	}
	else if (m->map[y][x - 1] == '0' && check_player(m, y, x - 1) == 0)
	{
		mlx_put_image_to_window(m->mlx, m->win, m->i.mob.img, \
								(x - 1) * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, m->i.floor.img, \
								x * 32, y * 32);
		m->map[y][x - 1] = 'M';
		m->map[y][x] = '0';
		check_collision(m, y, x - 1);
	}
}

void	where_mob(t_mlx *m, int y, int x)
{
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'M')
			{
				mob_move(m, y, x);
				x++;
			}
			x++;
		}
		y++;
	}
}
