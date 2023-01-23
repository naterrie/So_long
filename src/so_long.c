/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:34:28 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/23 17:44:44 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free (map);
}

void	fchange_sprite(t_mlx *m, t_image *i, int y, int x)
{
	mlx_put_image_to_window(m->mlx, m->win, i->chara.img, \
							m->x * 32, m->y * 32);
	mlx_put_image_to_window(m->mlx, m->win, i->floor.img, \
							(m->x - x) * 32, (m->y - y) * 32);
	if (m->map[m->y - y][m->x - x] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, i->door.img, \
								(m->x - x) * 32, (m->y - y) * 32);
	if (m->map[m->y - y][m->x - x] == '1')
	{
		mlx_put_image_to_window(m->mlx, m->win, i->wall.img, \
								(m->x - x) * 32, (m->y - y) * 32);
		return ;
	}
	where_mob(m, i, 0, 0);
}

int	so_long(char *file)
{
	t_mlx	mlx;
	int		window_lenght;
	int		window_weight;

	mlx.map = mapset(file);
	window_weight = 0;
	while (mlx.map[window_weight])
		window_weight++;
	window_weight = window_weight * 32;
	window_lenght = (ft_strlen(mlx.map[0]) - 1) * 32;
	set_placement(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, window_lenght, window_weight, "so_long");
	set_sprite(&mlx, 1, 0, 0);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
