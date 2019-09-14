/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:48:51 by edraco            #+#    #+#             */
/*   Updated: 2019/09/14 21:30:25 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ((char **)map);
}

void 	ft_pre_solver(t_map *map_start)
{
	char **map;
	t_map *cur_pointer;
	int len;

	len = 0;
	map = ft_create_map(ft_count_tetro(map_start));
	cur_pointer = map_start;
	/*DEBUG*/ ft_print_map(map);
	// ft_map_solver(map_start, map);
	ft_print_struct(map_start);
	while (cur_pointer)
	{
		if (!(ft_place_figure(cur_pointer, map)))
		{
			// ft_putstr("Map rewrited\n");
			len = ft_strlen(map[0]) + 1;
			map = ft_free_map(map);
			map = ft_create_map(len);
			cur_pointer = map_start;
			ft_putstr("___Map rewrited\n");
		}
		else
			cur_pointer = cur_pointer->next;
	}
	ft_putstr("Output:\n\n");
	ft_print_map(map);
}
