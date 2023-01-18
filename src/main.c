/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:07:29 by naterrie          #+#    #+#             */
/*   Updated: 2023/01/13 14:53:34 by naterrie         ###   ########lyon.fr   */
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
		return (1);
	if (check_path(argv[1]) == 1)
	{
		write (1, "ERROR\nIMPOSSIBLE MAP", 20);
		return (1);
	}
	if (so_long(argv[1]) == 1)
		return (1);
	return (0);
}
