/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:34:28 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/25 16:00:39 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			((char *)s)[i] = 0;
			i++;
		}
	}
}

int	check_player(t_mlx *mlx, int y, int x)
{
	if (mlx->y == y && mlx->x == x)
		return (1);
	return (0);
}

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

void	fchange_sprite(t_mlx *m, int y, int x)
{
	mlx_put_image_to_window(m->mlx, m->win, m->i.chara.img, \
							m->x * 32, m->y * 32);
	mlx_put_image_to_window(m->mlx, m->win, m->i.floor.img, \
							(m->x - x) * 32, (m->y - y) * 32);
	if (m->map[m->y - y][m->x - x] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, m->i.door.img, \
								(m->x - x) * 32, (m->y - y) * 32);
	if (m->map[m->y - y][m->x - x] == '1')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->i.wall.img, \
								(m->x - x) * 32, (m->y - y) * 32);
		return ;
	}
	where_mob(m, 0, 0);
}

int	so_long(char *file)
{
	t_mlx	mlx;
	int		window_lenght;
	int		window_weight;

	ft_bzero(&mlx, sizeof(t_mlx));
	mlx.map = mapset(file);
	window_weight = 0;
	while (mlx.map[window_weight])
		window_weight++;
	window_weight = window_weight * 32;
	window_lenght = (ft_strlen(mlx.map[0]) - 1) * 32;
	set_placement(&mlx);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (0);
	mlx.win = mlx_new_window(mlx.mlx, window_lenght, window_weight, "so_long");
	if (!mlx.win)
		return (mlx_destroy_display(mlx.mlx), 0);
	set_sprite(&mlx, 1, 0, 0);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
