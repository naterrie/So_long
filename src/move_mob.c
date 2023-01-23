/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:25:39 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/23 16:25:59 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_position_on_map(t_mlx *mlx, int i, int j)
{
	mlx->map[mlx->y][mlx->x] = '0';
	mlx->map[mlx->y + i][mlx->x + j] = 'P';
	printf("y = %d x = %d\n", mlx->y, mlx->x);
	int b = 0;
	while (mlx->map[b++])
		printf("%s", mlx->map[b]);
}

void	move_mobx(t_mlx *m, t_image *img, int y, int x)
{
	if (m->map[y][x + 1] == '0')\
	{
		mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
						(x + 1) * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
				x * 32, y * 32);
		m->map[y][x] = '0';
		m->map[y][x + 1] = 'M';
	}
	else if (m->map[y][x - 1] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
						(x - 1) * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
				x * 32, (y) * 32);
		m->map[y][x] = '0';
		m->map[y][x - 1] = 'M';
	}
}

void	move_mob(t_mlx *m, t_image *img, int y, int x)
{
	static int	numb;

	numb++;
	if (numb % 2 == 0)
	{
		if (m->map[y + 1][x] == '0')
		{
			mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
							x * 32, (y + 1) * 32);
			mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
					x * 32, y * 32);
			m->map[y][x] = '0';
			m->map[y + 1][x] = 'M';
		}
		else if (m->map[y - 1][x] == '0')
		{
			mlx_put_image_to_window(m->mlx, m->win, img->mob.img, \
							x * 32, (y - 1) * 32);
			mlx_put_image_to_window(m->mlx, m->win, img->floor.img, \
					x * 32, y * 32);
			m->map[y][x] = '0';
			m->map[y - 1][x] = 'M';
		}
	}
	else
		move_mobx(m, img, y, x);
}

void	ft_movemob(t_mlx *m, t_image *img, int y, int x)
{
	int	i;
	int	j;

	(void) img;
	(void) m;
	if (x != 0 && y != 0)
	{
		move_mob(m, img, y, x);
		return ;
	}
	else
	{
		i = 0;
		while (m->map[i])
		{
			j = 0;
			while (m->map[i][j])
			{
				if (m->map[i][j] == 'M')
					move_mob(m, img, i, j);
				j++;
			}
			i++;
		}
	}
}
