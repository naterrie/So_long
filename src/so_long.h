/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:21:32 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/23 15:57:55 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../mlx/mlx.h"

typedef struct sprite
{
	void	*img;
	int		w;
	int		h;
}	t_sprite;

typedef struct image
{
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	dooropen;
	t_sprite	chara;
	t_sprite	door;
	t_sprite	collect;
	t_sprite	mob;
	int			y;
	int			x;
}	t_image;

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

void	ft_putchar(char c);
void	ft_putnbr(int nb);
size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_next_buf(char *buf);
char	*ft_get_line(char *buf);
char	*ft_read_line(int fd, char *buf);
char	*ft_strjoin(char *buf, char *temp);

int		exit_collect(char **map);
int		ft_close(t_mlx *mlx);
int		key_hook(int key, t_mlx *mlx);
void	set_placement(t_mlx *mlx);
void	player_position(t_mlx *mlx, int i, int j);

int		check_door_closed(char **map);
void	change_movement(t_mlx *m, t_image *i, int y, int x);
void	set_sprite(t_mlx *mlx, int num, int y, int x);
void	check_char_window(t_image *i, t_mlx *m);

void	freemap(char **map);
void	fchange_sprite(t_mlx *m, t_image *i, int y, int x);

void	change_position_on_map(t_mlx *mlx, int i, int j);
void	ft_movemob(t_mlx *m, t_image *img, int y, int x);

#endif
