/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:07:29 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/23 18:18:21 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_mlx *m)
{
	if (m->i.dooropen.img)
		mlx_destroy_image(m->mlx, m->i.dooropen.img);
	mlx_destroy_image(m->mlx, m->i.wall.img);
	mlx_destroy_image(m->mlx, m->i.floor.img);
	mlx_destroy_image(m->mlx, m->i.collect.img);
	mlx_destroy_image(m->mlx, m->i.chara.img);
	mlx_destroy_image(m->mlx, m->i.door.img);
	mlx_destroy_image(m->mlx, m->i.mob.img);
	mlx_destroy_window(m->mlx, m->win);
	mlx_destroy_display(m->mlx);
	freemap(m->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "ERROR\nPLEASE EXECUTE WITH ONE FILE", 34);
		return (0);
	}
	if (check_map(argv[1]) == 1)
		return (1);
	if (check_path(argv[1]) == 1)
	{
		write (1, "ERROR\nIMPOSSIBLE MAP", 20);
		return (1);
	}
	if (so_long(argv[1]) == 1)
		return (1);
	return (0);
}
