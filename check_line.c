/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:19:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/10 11:05:30 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_invalid_char(char c)
{
	int	i;

	i = 0;
	i += check_map_char(c, 'P');
	i += check_map_char(c, 'E');
	i += check_map_char(c, 'C');
	i += check_map_char(c, '1');
	i += check_map_char(c, '0');
	i += check_map_char(c, '\n');
	return (i);
}

int	check_other_char(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (check_invalid_char(map[j][i]) == 0)
			{
				write(1, "ERROR\nOTHER CHARACTER DETECTED", 30);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	check_elements(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	item;
	int	start;

	j = 0;
	exit = 0;
	item = 0;
	start = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			exit += check_map_char(map[j][i], 'E');
			item += check_map_char(map[j][i], 'C');
			start += check_map_char(map[j][i], 'P');
			i++;
		}
		j++;
	}
	if (exit != 1 || start != 1 || item == 0)
		return (1);
	return (0);
}

int	check_mid_border(int count, char *map)
{
	int	i;

	i = 0;
	if (map[i] != '1')
		return (1);
	while (map[i] != '\n')
		i++;
	i--;
	if (map[i] != '1')
		return (1);
	if (i != count)
		return (1);
	return (0);
}

int	check_border(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 1;
	while (map[0][i] && map[0][i] == '1')
		i++;
	count = i - 1;
	while (map[j])
	{
		if (check_mid_border(count, map[j]) == 1)
			return (1);
		j++;
	}
	j--;
	i = 0;
	while (map[j][i] && map[j][i] == '1')
		i++;
	if ((i - 1) != count)
		return (1);
	return (0);
}
