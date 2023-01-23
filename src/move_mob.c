/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:25:39 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/23 18:35:18 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_position_on_map(t_mlx *mlx, int i, int j)
{
	if (mlx->map[mlx->y][mlx->x] == 'E')
		ft_close(mlx);
	mlx->map[mlx->y][mlx->x] = 'P';
	mlx->map[mlx->y - i][mlx->x - j] = '0';
}

void	mob_up_and_down(t_mlx *m, t_image *img, int y, int x)
{
	if (m->map[y - 1][x] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
						x * 32, (y - 1) * 32);
		mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
				x * 32, y * 32);
		m->map[y][x] = '0';
		m->map[y - 1][x] = 'M';
	}
	else if (m->map[y + 1][x] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
						x * 32, (y + 1) * 32);
		mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
				x * 32, y * 32);
		m->map[y][x] = '0';
		m->map[y + 1][x] = 'M';
	}
}

void	mob_right(t_mlx *m, t_image *img, int y, int x)
{
	if (m->map[y][x + 1] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
						(x + 1) * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
				x * 32, y * 32);
		m->map[y][x] = '0';
		m->map[y][x + 1] = 'M';
	}
	else
		mob_up_and_down(m, img, y, x);
}

void	mob_left(t_mlx *m, t_image *img, int y, int x)
{
	if (m->map[y][x - 1] == '0')\
	{
		mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
						(x - 1) * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
				x * 32, y * 32);
		m->map[y][x] = '0';
		m->map[y][x - 1] = 'M';
	}
	else
		mob_up_and_down(m, img, y, x);
}

void	where_mob(t_mlx *m, t_image *img, int y, int x)
{
	static int	numb;

	numb++;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'M' && numb % 2 == 0)
				mob_left(m, img, y, x);
			else if (m->map[y][x] == 'M')
				mob_right(m, img, y, x);
			x++;
		}
		y++;
	}
}
