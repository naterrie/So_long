/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:15:59 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/20 16:34:54 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_map_path(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'x')
		return (0);
	else if (map[x][y] != '1' || map[x][y] == 'x')
	{
		map[x][y] = 'x';
		set_map_path(map, x + 1, y);
		set_map_path(map, x - 1, y);
		set_map_path(map, x, y + 1);
		set_map_path(map, x, y - 1);
	}
	return (0);
}

int	check_collect(char **map, int x, int y)
{
	set_map_path(map, x, y);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E' || map[x][y] == 'C')
				return (free (map), 1);
			y++;
		}
		x++;
	}
	return (0);
}

int	check_path(char *file)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = mapset(file);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (check_map_char(map[x][y], 'P') == 1)
			{
				if (check_collect(map, x, y) == 1)
					return (free(map), 1);
				else
					return (free (map), 0);
			}
			y++;
		}
		x++;
	}
	return (0);
}
