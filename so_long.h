/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:21:32 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/06 14:35:50 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "minilibx/mlx.h"

int 	check_invalid_char(char c);
int 	check_other_char(char **map);
int	    check_elements(char **map);
int 	check_mid_border(int count, char *map);
int 	check_border(char **map);

int	    nbline(char *file);
int 	check_file_name(char *file);
int	    check_map_char(char charmap, char need);
char	**mapset(char *file)
int 	check_map(char *file);

void	set_char_after(char **map, int x, int y);
void	set_char_before(char **map, int x, int y);
int	    check_after_collect(char **map, int x, int y);
int 	check_before_collect(char **map, int x, int y);
int 	check_path_validity(char **map, int x, int y);
int	    check_path(char *file);

size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_next_buf(char *buf);
char	*ft_get_line(char *buf);
char	*ft_read_line(int fd, char *buf);
char	*ft_strjoin(char *buf, char *temp);

#endif
