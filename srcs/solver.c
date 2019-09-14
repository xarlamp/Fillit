/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:48:51 by edraco            #+#    #+#             */
/*   Updated: 2019/09/14 15:41:50 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void 	ft_pre_solver(t_map *map_start)
{
	char **map;

	map = ft_create_map(ft_count_tetro(map_start));
	/*DEBUG*/ ft_print_map(map);
	// ft_map_solver(map_start, map);

	while (map_start)
	{
		ft_place_figure(map_start, map);
		map_start = map_start->next;
	}

}
