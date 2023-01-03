/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:20:45 by naterrie          #+#    #+#             */
/*   Updated: 2022/11/25 20:11:27 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	putnbr(int nb);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	ft_printf(const char *s, ...);
int	ft_putunsigned_nbr(unsigned int nb);
int	ft_Check_Caracter(char *c, va_list args);
int	ft_putptr(unsigned long long nbr, int n);
int	ft_puthexa_nbr(unsigned int nbr, const char *base);

#endif
