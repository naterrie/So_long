/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:19:31 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/03 15:41:21 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_border(char **map)
{
	int	i;
	int	j;
	int	count;

	j = 1;
	while (map[0][i] == '1' || map[0][i])
		i++;
	count = i;
	while (map[j])
	{
		i = 0;
		if (map[j][i] != '1')
			return (1);
		while (map[j][i] && map[j][i] != '\n')
			i++;
		if (i != count || map[j][i] != '1')
			return (1);
		j++;
	}
	while (map[j][i] == '1' || map[j][i])
		i++;
	return (0);
}
