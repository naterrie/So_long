/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:21:32 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/03 15:49:51 by naterrie         ###   ########lyon.fr   */
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

int		check_elements(char **map);
int		check_file_name(char *file);
int		check_border(char **map);

int		nbline(char *file);
int		check_file_name(char *file);
int		check_map_char(char map, char need);
char	**mapset(char *file);
int		check_map(char *file);

size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_next_buf(char *buf);
char	*ft_get_line(char *buf);
char	*ft_read_line(int fd, char *buf);
char	*ft_strjoin(char *buf, char *temp);

int		putnbr(int nb);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_printf(const char *s, ...);
int		ft_putunsigned_nbr(unsigned int nb);
int		ft_Check_Caracter(char *c, va_list args);
int		ft_putptr(unsigned long long nbr, int n);
int		ft_puthexa_nbr(unsigned int nbr, const char *base);

#endif
