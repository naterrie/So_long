/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:25:21 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/25 17:33:31 by naterrie         ###   ########lyon.fr   */
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

void	change_movement(t_mlx *m, int y, int x)
{
	int	j;
	int	k;

	j = whereisdoorx(m->map);
	k = whereisdoory(m->map);
	if (exit_collect(m->map) == 0)
	{
		mlx_put_image_to_window(m->mlx, m->win, m->i.floor.img, \
							j * 32, k * 32);
		mlx_put_image_to_window(m->mlx, m->win, m->i.dooropen.img, \
							j * 32, k * 32);
	}
	if (m->map[m->y][m->x] != 'E')
		mlx_put_image_to_window(m->mlx, m->win, m->i.floor.img, \
								m->x * 32, m->y * 32);
	if (m->map[m->y - y][m->x - x] == 'E')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->i.door.img, \
								(m->x - x) * 32, (m->y - y) * 32);
	}
	fchange_sprite(m, y, x);
}

void	check_char_window(t_mlx *m)
{
	while (m->map[m->i.y])
	{
		m->i.x = -1;
		while (m->map[m->i.y][++m->i.x])
		{
			mlx_put_image_to_window(m->mlx, m->win, m->i.floor.img, \
									m->i.x * 32, m->i.y * 32);
			if (m->map[m->i.y][m->i.x] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->i.wall.img, \
								m->i.x * 32, m->i.y * 32);
			if (m->map[m->i.y][m->i.x] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->i.door.img, \
								m->i.x * 32, m->i.y * 32);
			if (m->map[m->i.y][m->i.x] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->i.collect.img, \
								m->i.x * 32, m->i.y * 32);
			if (m->map[m->i.y][m->i.x] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->i.chara.img, \
							m->x * 32, m->y * 32);
			if (m->map[m->i.y][m->i.x] == 'M')
				mlx_put_image_to_window(m->mlx, m->win, m->i.mob.img, \
							m->i.x * 32, m->i.y * 32);
		}
		m->i.y++;
	}
}

void	set_sprite(t_mlx *m, int num, int y, int x)
{
	m->i.y = 0;
	if (num == 1)
	{	
		m->i.mob.img = mlx_xpm_file_to_image(m->mlx, "image/mob.xpm", \
										&m->i.dooropen.w, &m->i.dooropen.h);
		m->i.dooropen.img = mlx_xpm_file_to_image(m->mlx, "image/dooropen.xpm", \
										&m->i.dooropen.w, &m->i.dooropen.h);
		m->i.door.img = mlx_xpm_file_to_image(m->mlx, "image/door.xpm", \
										&m->i.door.w, &m->i.door.h);
		m->i.floor.img = mlx_xpm_file_to_image(m->mlx, "image/floor.xpm", \
										&m->i.floor.w, &m->i.floor.h);
		m->i.wall.img = mlx_xpm_file_to_image(m->mlx, "image/wall.xpm", \
										&m->i.wall.w, &m->i.wall.h);
		m->i.chara.img = mlx_xpm_file_to_image(m->mlx, "image/character.xpm", \
										&m->i.wall.w, &m->i.wall.h);
		m->i.collect.img = mlx_xpm_file_to_image(m->mlx, "image/collect.xpm", \
										&m->i.collect.w, &m->i.collect.h);
		check_char_window(m);
	}
	if (num == 2)
		change_movement(m, y, x);
}
