/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:31:23 by edraco            #+#    #+#             */
/*   Updated: 2019/09/12 17:41:46 by edraco           ###   ########.fr       */
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
			if (lfig[i][j] == '#')
				return(j);
			i++;
		}
		j++;
	}
	return (0);
}

static int	ft_place_figure_tryer_mapper(char **map, int i, int j, int x, int y)
{
	while (x)
	{
		while (y)
		{
			//Check map for free space to place figure. But do not forget about
			//size of map when you offsetting an pointer.
		}
	}
}

static int	ft_place_figure_tryer(char **figure, char **map, int i, int j)
{
	int x;
	int y;

	x = ft_find_x;
	y = ft_find_y;
	ft_place_figure_tryer_mapper(map, i, j, 4 - x, 4 - y)
}

int	ft_place_figure(char **figure, char **map)
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
			if (ft_place_figure_tryer(figure, map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
