/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:34:28 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/10 14:45:51 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *file)
{
	int		fd;
	void	*mlx;
	void	*mlx_win;
	char	*path_image;

	path_image = "brick.png";
	mlx = mlx_init();
	fd = open(file, O_RDONLY);
	close(fd);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	mlx_loop(mlx);
	return (0);
}
