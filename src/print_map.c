/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:25:21 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/18 15:01:53 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char_window(t_image *img, t_mlx *mlx, char C)
{
	if (C == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->wall.img, \
								img->x * 64, img->y * 64);
	if (C == '0' || C == 'C' || C == 'E' || C == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->floor.img, \
								img->x * 64, img->y * 64);
	if (C == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->door.img, \
								img->x * 64, img->y * 64);
	//if (C == 'C')
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->chara.img, \
							mlx->x * 64, mlx->y * 64);
}

void	print_map(t_mlx mlx)
{
	t_image	img;

	img.y = 0;
	img.wall.path = "image/wall.xpm";
	img.floor.path = "image/floor.xpm";
	img.door.path = "image/door.xpm";
	img.chara.path = "image/character.xpm";
	img.door.img = mlx_xpm_file_to_image(mlx.mlx, img.door.path, \
										&img.door.w, &img.door.h);
	img.floor.img = mlx_xpm_file_to_image(mlx.mlx, img.floor.path, \
										&img.floor.w, &img.floor.h);
	img.wall.img = mlx_xpm_file_to_image(mlx.mlx, img.wall.path, \
										&img.wall.w, &img.wall.h);
	img.chara.img = mlx_xpm_file_to_image(mlx.mlx, img.chara.path, \
										&img.wall.w, &img.wall.h);
	while (mlx.map[img.y])
	{
		img.x = 0;
		while (mlx.map[img.y][img.x])
		{
			check_char_window(&img, &mlx, mlx.map[img.y][img.x]);
			img.x++;
		}
		img.y++;
	}
}
