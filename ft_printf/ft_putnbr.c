/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:44:05 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/03 15:17:44 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_puthexa_nbr(unsigned int nbr, const char *base)
{
	int	count;

	count = 0;
	if (nbr > 15)
	{
		count = ft_puthexa_nbr(nbr / 16, base);
		count += ft_puthexa_nbr(nbr % 16, base);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}

int	ft_putunsigned_nbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count = ft_putunsigned_nbr(nb / 10);
		count += ft_putunsigned_nbr(nb % 10);
	}
	else
	{
		count += ft_putchar(nb + 48);
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		size = size + ft_putchar('-');
		n = -n;
	}
	return (size + putnbr(n));
}

int	putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i = putnbr(nb / 10);
		i = i + putnbr(nb % 10);
	}
	else
	{
		i = i + ft_putchar(nb + 48);
	}
	return (i);
}
