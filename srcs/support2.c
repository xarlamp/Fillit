/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:20:24 by edraco            #+#    #+#             */
/*   Updated: 2019/09/15 14:37:52 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_free_map(char **map)
{
	int i;
	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_error();
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit (0);
}

static void		ft_map_filler(char ***lmap, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < i)
	{
		while (k < i)
		{
			(*lmap)[j][k] = '.';
			k++;
		}
		k = 0;
		j++;
	}
}

char **ft_create_map(int i)
{
	char **map;
	int j;

	j = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (i + 1))))
		ft_error();
 	map[i] = 0;
	while (j < i)
	{
		if (!(map[j] = (char *)malloc(sizeof(char) * (i + 1))))
				ft_error_free_map(map);
		map[j][i] = 0;
		j++;
	}
	ft_map_filler(&map, i);
	// ft_putstr("Map has been created. Size is: ");
	// ft_putnbr(i);
	// ft_putchar('\n');
	return (map);
}
