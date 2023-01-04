/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:55:11 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/03 15:17:37 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_caracter(int c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i = ft_putptr(va_arg(args, unsigned long long), 0) + 2;
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i = ft_putunsigned_nbr(va_arg(args, unsigned int));
	else if (c == 'x')
		i = ft_puthexa_nbr(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		i = ft_puthexa_nbr(va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s || write (1, 0, 0))
		return (-1);
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_check_caracter(s[i], args);
			if (s[i] == '\0')
				return (count);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end (args);
	return (count);
}
