/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:14:33 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/06 12:25:48 by naterrie         ###   ########lyon.fr   */
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
	close(fd);
	return (line + 1);
}

int	check_file_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i--;
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
	write(1, "ERROR\nWRONG FILE NAME", 21);
	return (1);
}

int	check_map_char(char charmap, char need)
{
	if (charmap == need)
		return (1);
	else
		return (0);
}

char	**mapset(char *file)
{
	char	**map;
	int		i;
	int		fd;
	int		line;

	i = 0;
	line = nbline(file);
	map = malloc(sizeof(char *) * line);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (i < line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
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
		write(1, "ERROR\nWRONG NUMBER ELEMENTS", 27);
		return (free(map), 1);
	}
	if (check_border(map) == 1)
	{
		write(1, "ERROR\nWRONG BORDER !", 20);
		return (free(map), 1);
	}
	if (check_other_char(map) == 1)
		return (1);
	free (map);
	return (0);
}
