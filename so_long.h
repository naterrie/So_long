/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:21:32 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/13 17:24:38 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "mlx/mlx.h"

typedef struct mlx
{
	void	*mlx;
	void	*win;
	char	**map;
	int		y;
	int		x;
}	t_mlx;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		so_long(char *file);

int		check_invalid_char(char c);
int		check_other_char(char **map);
int		check_elements(char **map);
int		check_mid_border(int count, char *map);
int		check_border(char **map);

int		nbline(char *file);
int		check_file_name(char *file);
int		check_map_char(char charmap, char need);
char	**mapset(char *file);
int		check_map(char *file);

int		set_map_path(char **map, int x, int y);
int		check_collect(char **map, int x, int y);
int		check_path(char *file);

size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_next_buf(char *buf);
char	*ft_get_line(char *buf);
char	*ft_read_line(int fd, char *buf);
char	*ft_strjoin(char *buf, char *temp);

int		key_hook(int key, t_mlx *mlx_test);
void	set_placement(t_mlx *mlx_test);
int		player_position(t_mlx *mlx_test, int i, int j);

void	printmap(char **map);

#endif
