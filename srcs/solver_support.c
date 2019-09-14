/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:31:23 by edraco            #+#    #+#             */
/*   Updated: 2019/09/14 22:15:59 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_find_x(char **lfig)
{
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (lfig[i][j] == '#')
				return(i);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_find_y(char **lfig)
{
	int i;
	int j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (lfig[i][j] != '.')
				return(j);
			i++;
		}
		j++;
	}
	return (0);
}
static int	ft_place_figure_tryer_mapper(t_map *map_start, char **map, int i,
	 			int j, int x, int y)
{
	int a;
	int b;
	int m;
	int n;
	int size;

	a = x;
	m = 0;
	size = (int)ft_strlen(map[0]);
	if ((x + i >= (int)ft_strlen(map[0])) || (y + j >= (int)ft_strlen(map[0])))
		return(0);
	while (a < 4)
	{
		b = y;
		n = 0;
		while (b < 4)
		{
			if (/*(i + m <= size) && (j + n <= size) &&*/ (map_start->line[a][b] == '#') && (map[i + m][j + n] != '.'))
				return (0);
			b++;
			n++;
		}
		a++;
		m++;
	}
	return (1);
}

static int	ft_place_figure_tryer_imprinter(t_map *map_start, char **map, int i,
	 			int j, int x, int y)
{
	int a;
	int b;
	int m;
	int n;

	a = x;
	m = 0;
	while (a < 4)
	{
		b = y;
		n = 0;
		while (b < 4)
		{
			if (map_start->line[a][b] == '#')
				map[i + m][j + n] = 64 + map_start->nbr_of_block;
			b++;
			n++;
		}
		a++;
		m++;
	}
ft_putstr("This was block #");
ft_putnbr(map_start->nbr_of_block);
ft_putchar('\n');
return (1);
}

static int	ft_place_figure_tryer(t_map *map_start, char **map, int i, int j)
// This function is placing figure on map if it possible.
{
	int x;
	int y;

	x = ft_find_x(map_start->line);
	y = ft_find_y(map_start->line);
	if (ft_place_figure_tryer_mapper(map_start, map, i, j, x, y))
		if (ft_place_figure_tryer_imprinter(map_start, map, i, j, x, y))
			return (1);
	return (0);
}

int	ft_place_figure(t_map *map_start, char **map)
// This function is tryng to put figure in any empty spot on map
//Iterates over all places on map
// If this function returns 0, then you need to regenerate your map
{
	int i;
	int j;
	int size;

	i = 0;
	size = ft_strlen(map[0]);
	ft_putstr("size is = ");
	ft_putnbr(size);
	ft_putchar('\n');
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_place_figure_tryer(map_start, map, i, j))
			{
				ft_putstr("i/j is ");
				ft_putnbr(i);
				ft_putchar(' ');
				ft_putnbr(j);
				ft_putchar('\n');
				ft_putstr("Figure placed and Figure_tryer has returned 1\n");
				ft_putstr("Map currently is:\n");
				ft_print_map(map);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_putstr("Figure_tryer has returned 0\n");
	return (0);
}
