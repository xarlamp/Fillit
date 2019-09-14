/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:48:51 by edraco            #+#    #+#             */
/*   Updated: 2019/09/14 17:46:04 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void 	ft_pre_solver(t_map *map_start)
{
	char **map;
	t_map *cur_pointer;

	map = ft_create_map(ft_count_tetro(map_start));
	cur_pointer = map_start;
	/*DEBUG*/ ft_print_map(map);
	// ft_map_solver(map_start, map);

	while (cur_pointer)
	{
		if (ft_place_figure(map_start, map))
		{
			map = ft_create_map(ft_strlen(map[0]) + 1);
			cur_pointer = map_start;
		}
		cur_pointer = cur_pointer->next;
	}
}
