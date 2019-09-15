/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:48:51 by edraco            #+#    #+#             */
/*   Updated: 2019/09/15 22:22:17 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void ft_sider_worker(char **line)
{
	int x;
	int y;
	int i;
	int j;
	int res_y;
	char buff;

	i = 0;
	x = ft_find_x(line);
	y = ft_find_y(line);
	// ft_putstr("x = ");
	// ft_putnbrendl(x);
	// ft_putstr("y = ");
	// ft_putnbrendl(y);
	while (x < 4)
	{
		res_y = y;
		j = 0;
		while (res_y < 4)
		{
			buff = line[x][res_y];
			line[x][res_y] = '.';
			line[i][j] = buff;
			res_y++;
			j++;
		}
		x++;
		i++;
	}
}

static void	ft_sider(t_map *map_start)
{
	while (map_start)
	{
		ft_sider_worker(map_start->line);
		map_start = map_start->next;
	}
}

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
	ft_sider(map_start);
	map = ft_create_map(ft_count_tetro(map_start));
	cur_pointer = map_start;
	// ft_putstr("The current map is:\n");
	// /*DEBUG*/ ft_print_map(map);
	// ft_print_struct(map_start);
	while (cur_pointer)
	{
		if (!(ft_place_figure(cur_pointer, map)))
		{
			// ft_putstr("Map rewriting\n");
			len = ft_strlen(map[0]) + 1;
			map = ft_free_map(map);
			map = ft_create_map(len);
			cur_pointer = map_start;
			// ft_print_map(map);
			// ft_putstr("___Map rewrited\n");
		}
		else
			cur_pointer = cur_pointer->next;
	}
	// ft_putstr("Output:\n\n");
	ft_print_map(map);
}
