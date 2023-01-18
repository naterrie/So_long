/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:25:21 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/18 18:15:33 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_movement(t_mlx *m, t_image *i, int y, int x)
{
	mlx_put_image_to_window(m->mlx, m->win, i->floor.img, m->x * 64, m->y * 64);
	mlx_put_image_to_window(m->mlx, m->win, i->chara.img, m->x * 64, m->y * 64);
	mlx_put_image_to_window(m->mlx, m->win, i->floor.img, (m->x - x) * 64, (m->y - y) * 64);
	if (m.map[m->y - y][m->x - x] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, i->door.img, (m->x - x) * 64, (m->y - y) * 64);
}

void	check_char_window(t_image *i, t_mlx *m)
{
	while (m->map[i->y])
	{
		i->x = 0;
		while (m->map[i->y][i->x])
		{
			if (m->map[i->y][i->x] == '1')
				mlx_put_image_to_window(m->mlx, m->win, i->wall.img, \
								i->x * 64, i->y * 64);
			if (m->map[i->y][i->x] == '0' || m->map[i->y][i->x] == 'C' || \
				m->map[i->y][i->x] == 'E' || m->map[i->y][i->x] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, i->floor.img, \
								i->x * 64, i->y * 64);
			if (m->map[i->y][i->x] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, i->door.img, \
								i->x * 64, i->y * 64);
			if (m->map[i->y][i->x] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, i->collect.img, \
								i->x * 64, i->y * 64);
			mlx_put_image_to_window(m->mlx, m->win, i->chara.img, \
							m->x * 64, m->y * 64);
			i->x++;
		}
		i->y++;
	}

}

void	set_sprite(t_mlx *mlx, int num, int y, int x)
{
	t_image	img;

	img.y = 0;
	img.wall.path = "image/wall.xpm";
	img.floor.path = "image/floor.xpm";
	img.door.path = "image/door.xpm";
	img.chara.path = "image/character.xpm";
	img.collect.path = "image/collect.xpm";
	img.door.img = mlx_xpm_file_to_image(mlx->mlx, img.door.path, \
										&img.door.w, &img.door.h);
	img.floor.img = mlx_xpm_file_to_image(mlx->mlx, img.floor.path, \
										&img.floor.w, &img.floor.h);
	img.wall.img = mlx_xpm_file_to_image(mlx->mlx, img.wall.path, \
										&img.wall.w, &img.wall.h);
	img.chara.img = mlx_xpm_file_to_image(mlx->mlx, img.chara.path, \
										&img.wall.w, &img.wall.h);
	img.collect.img = mlx_xpm_file_to_image(mlx->mlx, img.collect.path, \
										&img.collect.w, &img.collect.h);
	if (num == 1)
		check_char_window(&img, mlx);
	if (num == 2)
		change_movement(mlx, &img, y, x);
}
