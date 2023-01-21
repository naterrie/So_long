/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:25:21 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/21 16:55:01 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	whereisdoory(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	whereisdoorx(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

void	change_movement(t_mlx *m, t_image *i, int y, int x)
{
	int	j;
	int	k;

	j = whereisdoorx(m->map);
	k = whereisdoory(m->map);
	if (exit_collect(m->map) == 0)
	{
		mlx_put_image_to_window(m->mlx, m->win, i->floor.img, \
							j * 32, k * 32);
		mlx_put_image_to_window(m->mlx, m->win, i->dooropen.img, \
							j * 32, k * 32);
	}
	if (m->map[m->y][m->x] != 'E')
		mlx_put_image_to_window(m->mlx, m->win, i->floor.img, \
								m->x * 32, m->y * 32);
	if (m->map[m->y - y][m->x - x] == 'E')
	{
		mlx_put_image_to_window(m->mlx, m->win, i->door.img, \
								(m->x - x) * 32, (m->y - y) * 32);
	}
	fchange_sprite(m, i, y, x);
}

void	check_char_window(t_image *i, t_mlx *m)
{
	while (m->map[i->y])
	{
		i->x = 0;
		int b = 0;
		while (m->map[b])
			printf("%s\n", m->map[b++]);
		while (m->map[i->y][i->x])
		{
			if (m->map[i->y][i->x] == '1')
				mlx_put_image_to_window(m->mlx, m->win, i->wall.img, \
								i->x * 32, i->y * 32);
			if (m->map[i->y][i->x] == '0' || m->map[i->y][i->x] == 'C' || \
				m->map[i->y][i->x] == 'E' || m->map[i->y][i->x] == 'P' || m->map[i->y][i->x] == 'M')
				mlx_put_image_to_window(m->mlx, m->win, i->floor.img, \
								i->x * 32, i->y * 32);
			if (m->map[i->y][i->x] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, i->door.img, \
								i->x * 32, i->y * 32);
			if (m->map[i->y][i->x] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, i->collect.img, \
								i->x * 32, i->y * 32);
			mlx_put_image_to_window(m->mlx, m->win, i->chara.img, \
							m->x * 32, m->y * 32);
			if (m->map[i->y][i->x] == 'M')
				mlx_put_image_to_window(m->mlx, m->win, i->mob.img, \
							m->x * 32, m->y * 32);
			i->x++;
		}
		i->y++;
	}
}

void	set_sprite(t_mlx *mlx, int num, int y, int x)
{
	t_image	img;

	img.y = 0;
	img.mob.img = mlx_xpm_file_to_image(mlx->mlx, "image/mob.xpm", \
											&img.dooropen.w, &img.dooropen.h);
	img.dooropen.img = mlx_xpm_file_to_image(mlx->mlx, "image/dooropen.xpm", \
											&img.dooropen.w, &img.dooropen.h);
	img.door.img = mlx_xpm_file_to_image(mlx->mlx, "image/door.xpm", \
										&img.door.w, &img.door.h);
	img.floor.img = mlx_xpm_file_to_image(mlx->mlx, "image/floor.xpm", \
										&img.floor.w, &img.floor.h);
	img.wall.img = mlx_xpm_file_to_image(mlx->mlx, "image/wall.xpm", \
										&img.wall.w, &img.wall.h);
	img.chara.img = mlx_xpm_file_to_image(mlx->mlx, "image/character.xpm", \
										&img.wall.w, &img.wall.h);
	img.collect.img = mlx_xpm_file_to_image(mlx->mlx, "image/collect.xpm", \
										&img.collect.w, &img.collect.h);
	if (num == 1)
		check_char_window(&img, mlx);
	if (num == 2)
		change_movement(mlx, &img, y, x);
}
