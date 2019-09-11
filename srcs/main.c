/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:48:28 by edraco            #+#    #+#             */
/*   Updated: 2019/09/11 19:03:22 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int		main(int ac, char **av)
{
	int	fd;
	t_map *map_start;

	map_start = 0;
	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(EXIT_FAILURE);
	}
	if (valid_or_not(fd = open(av[1], O_RDONLY), &map_start) != 1)
	{
		ft_putstr("Error!\n");
	}
	else
		ft_putstr("All right\n");
	ft_pre_solver(map_start);
	return (0);
}
