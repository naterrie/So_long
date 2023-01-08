/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:15:59 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/06 12:31:09 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_char_check(char **map, int x, int y)
{
	if (map[x][y] == '1')
		return (0);
	else (map[x][y] != '1')
	{
		map[x][y] = 'x';
		set_char_check(map, x + 1, y,);
		set_char_check(map, x - 1 , y);
		set_char_check(map, y + 1, x,);
		set_char_check(map, y - 1, x,);
	}
}

int	check_after_collect()
{
	return (0);
}

int	check_before_collect()
{
	return (0);
}

int	check_path_validity(char **map, int x, int y)
{
	if (check_before_collect == 1)
		return (1);
	if (check_after_collect == 1)
		return (1);
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
				if (check_path_validity(map, x, y) == 1)
					return (1);
				else
					return (0);
			}
			y++;
		}
		x++;
	}
	return (free (map), 0);
}
