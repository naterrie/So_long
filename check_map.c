/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:14:33 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/03 15:49:55 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nbline(char *file)
{
	int	line;
	int	fd;

	line = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd) != 0)
		line++;
	return (line);
}

int	check_file_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i] == 'r')
	{
		i--;
		if (file[i] == 'e')
		{
			i--;
			if (file[i] == 'b')
			i--;
			if (file[i] == '.')
				return (0);
		}
	}
	ft_printf("ERROR\n WRONG FILE NAME");
	return (1);
}

int	check_map_char(char map, char need)
{
	if (map == need)
		return (1);
	else
		return (0);
}

char	**mapset(char *file)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = malloc(sizeof(char *) * nbline);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (map[i])
	{
		map[i] = get_next_line(fd);
		i++;
	}
	return (map);
}

int	check_map(char *file)
{
	char	**map;
	int		i;
	int		line;
	int		fd;

	line = nbline(file);
	if (check_file_name(file) == 1)
		return (1);
	map = mapset(file);
	if (check_elements(map) == 1)
	{
		ft_printf("ERROR\n WRONG NUMBER ELEMENTS");
		return (1);
	}
	if (check_border(map) == 1)
	{
		ft_printf("ERROR\n WRONG BORDER !");
		return (1);
	}
	return (0);
}
