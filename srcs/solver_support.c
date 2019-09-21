/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:31:23 by edraco            #+#    #+#             */
/*   Updated: 2019/09/21 16:04:21 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
static int	ft_place_figure_tryer_mapper(t_map *map_start, char **map, int i,
	 			int j, int x, int y)
{
	int a;
	int b;
	int m;
	int n;
	int size;

	// ft_putstr("Debug4\n");
	a = x;
	m = 0;
	size = (int)ft_strlen(map[0]);
	if ((x + i >= (int)ft_strlen(map[0])) || (y + j >= (int)ft_strlen(map[0])))
		return(0);
	// ft_putstr("Debug4.1\n");
	while (a < 4 - x)
	{
		b = y;
		n = 0;
		while (b < 4 - y)
		{
			// ft_putstr("_____GRAND DEBUG_____\n");
			// ft_putstr("size = ");
			// ft_putnbrendl(size);
			// ft_putstr("i = ");
			// ft_putnbrendl(i);
			// ft_putstr("j = ");
			// ft_putnbrendl(j);
			// ft_putstr("m = ");
			// ft_putnbrendl(m);
			// ft_putstr("n = ");
			// ft_putnbrendl(n);
			// ft_putstr("a = ");
			// ft_putnbrendl(a);
			// ft_putstr("b = ");
			// ft_putnbrendl(b);
			// ft_putstr("i + m = ");
			// ft_putnbrendl(i + m);
			// ft_putstr("j + n = ");
			// ft_putnbrendl(j + n);
			if ((i + m >= size) || (j + n >= size) || ((map_start->line[a][b] == '#') && (map[i + m][j + n] != '.')))
				return (0);
			// ft_putstr("Debug4.3\n");
			b++;
			n++;
		}
		a++;
		m++;
	}
	return (1);
}
*/

// static int	ft_place_figure_tryer_imprinter(t_map *map_start, char **map, int i,
// 	 			int j, int x, int y)
// {
// 	int a;
// 	int b;
// 	int m;
// 	int n;
//
// 	a = x;
// 	m = 0;
// 	while (a < 4)
// 	{
// 		b = y;
// 		n = 0;
// 		while (b < 4)
// 		{
// 			if (map_start->line[a][b] == '#')
// 				map[i + m][j + n] = 64 + map_start->nbr_of_block;
// 			b++;
// 			n++;
// 		}
// 		a++;
// 		m++;
// 	}
// 	return (1);
// }

static int	ft_place_figure_tryer_mapper(t_map *map_start, char **map, int i,
	 			int j, int size)
{
	int x_end;
	int y_end;
	int x;
	int y;

	// ft_putstr("Mapper for i = ");
	// ft_putnbr(i);
	// ft_putstr(", j = ");
	// ft_putnbr(j);
	// ft_putstr(" - started\n");
	x = 0;
	x_end = ft_find_x_end(map_start->line);
	y_end = ft_find_y_end(map_start->line);
	// ft_putstr("x_end = ");
	// ft_putnbrendl(x_end);
	// ft_putstr("y_end = ");
	// ft_putnbrendl(y_end);
	if ((x_end + i >= size) || (y_end + j >= size))
		return(0);
	while(x <= x_end)
	{
		y = 0;
		while (y <= y_end)
		{
			// ft_putstr("x = ");
			// ft_putnbrendl(x);
			// ft_putstr("y = ");
			// ft_putnbrendl(y);
			// ft_putstr("i + x = ");
			// ft_putnbrendl(i + x);
			// ft_putstr("j + y = ");
			// ft_putnbrendl(j + y);
			if (  ((map_start->line[x][y] == '#') && (map[i + x][j + y] != '.')))
				return(0);
			y++;
		}
		x++;
	}
	return (1);
}


static int	ft_place_figure_tryer_imprinter(t_map *map_start, char **map, int i,
	 			int j)
{
	int x_end;
	int y_end;
	int x;
	int y;

	// ft_putstr("Tryer started.\n");
	x = 0;
	x_end = ft_find_x_end(map_start->line);
	y_end = ft_find_y_end(map_start->line);
	// ft_putstr("x_end = ");
	// ft_putnbrendl(x_end);
	// ft_putstr("y_end = ");
	// ft_putnbrendl(y_end);
	while (x <= x_end)
	{
		y = 0;
		while (y <=y_end)
		{
			if (map_start->line[x][y] == '#')
				map[i + x][j + y] = 64 + map_start->nbr_of_block;
			y++;
		}
		x++;
	}
	return (1);
}

static int	ft_place_figure_tryer(t_map *map_start, char **map, int i, int j,
				int size)
// This function is placing figure on map if it possible.
{
	// ft_putstr("Debug1\n");
	// // ft_putstr("Debug2\n");
	// ft_putstr("Debug3\n");
	if (ft_place_figure_tryer_mapper(map_start, map, i, j, size))
		if (ft_place_figure_tryer_imprinter(map_start, map, i, j))
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
	int fence;

	i = 0;
	fence = 2;
	size = ft_strlen(map[0]);
	// ft_putstr("size is = ");
	// ft_putnbr(size);
	// ft_putchar('\n');
	while (fence <= size)
	{
		while (i < fence)
		{
			j = 0;
			while (j < fence)
			{
				if (ft_place_figure_tryer(map_start, map, i, j, fence))
				{
					// ft_putstr("i/j is ");
					// ft_putnbr(i);
					// ft_putchar(' ');
					// ft_putnbr(j);
					// ft_putchar('\n');
					// ft_putstr("Figure placed and Figure_tryer has returned 1\n");
					// ft_putstr("Map currently is:\n");
					// ft_print_map(map);
					return (1);
				}
				j++;
			}
			i++;
		}
		fence++;
		i = 0;
		j = 0;
	}
	// ft_putstr("Figure_tryer has returned 0\n");
	return (0);
}
