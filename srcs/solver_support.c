/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:31:23 by edraco            #+#    #+#             */
/*   Updated: 2019/09/14 15:57:22 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// static int	ft_find_x(char **lfig)
// {
// 	int i;
// 	int j;
//
// 	i = 0;
// 	while (i < 5)
// 	{
// 		j = 0;
// 		while (j < 5)
// 		{
// 			if (lfig[i][j] == '#')
// 				return(i);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }
//
// static int	ft_find_y(char **lfig)
// {
// 	int i;
// 	int j;
//
// 	j = 0;
// 	while (j < 5)
// 	{
// 		i = 0;
// 		while (i < 5)
// 		{
// 			if (lfig[i][j] == '#')
// 				return(j);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (0);
// }

static int	ft_place_figure_tryer_mapper(char **map, int i, int j, int x, int y)
//This function is checking nearby places on accessability for placiong figure.
{
	int a;
	int b;

	a = x;
	if ((x + i >= ft_strlen(map[0])) || (y + j >= ft_strlen(map[0]))
		return(0);
	while (a)
	{
		b = y;
		while (b)
		{
			//Check map for free space to place figure. But do not forget about
			//size of map when you offsetting an pointer.
			if (map[a + i][b + j] != '.')
				return (0);
			b--;
		}
		a--;
	}
	return (1);
}

static int	ft_place_figure_tryer_imprinter(t_map *map_start, char **map, int i,
	 			int j, int x, int y)
//This function is imprinting an figure on map
{
	int a;
	int b;

	a = x;
	while (a)
	{
		b = y;
		while (b)
		{
			map[a + i][b + j]
		}
	}
}
static int	ft_place_figure_tryer(t_map map_start, char **map, int i, int j)
// This function is placing figure on map if it possible.
{
	int x;
	int y;

	x = ft_find_x;
	y = ft_find_y;
	if (ft_place_figure_tryer_mapper(map, i, j, 4 - x, 4 - y))
		ft_place_figure_tryer_imprinter(map_start, map, i, j, 4 - x, 4 - y);
}

int	ft_place_figure(t_map map_start, char **map)
// This function is tryng to put figure in any empty spot on map
//Iterates over all places on map
// If this function returns 0, then you need to regenerate your map
{
	int i;
	int j;
	int size;

	i = 0;
	size = ft_strlen(map[0]);
	while (i < size) //Probably size + 1
	{
		j = 0;
		while (j < size) //Probably size + 1
		{
			if (ft_place_figure_tryer(map_start, map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
