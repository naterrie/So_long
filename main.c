/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:07:29 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/05 18:18:56 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "ERROR\nPLEASE EXECUTE WITH ONE FILE", 34);
		return (0);
	}
	if (check_map(argv[1]) == 1)
		return (0);
	if (check_path(argv[1] == 1))
		return (1);
	write(1, "it's working", 12);
	return (0);
}
