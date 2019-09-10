/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:08:19 by edraco            #+#    #+#             */
/*   Updated: 2019/09/10 21:25:30 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *ft_charset(int size)
{
	char *current_buf;
	int i;

	i = 0;
	current_buf = (char *)malloc(sizeof(char) * size);
	while (i < size - 1)
	{
		current_buf[i] = '!';
		i++;
	}
	current_buf[i] = '\0';
	return (current_buf);
}

int		ft_count_tetro(t_map *start)
{
	int i;
	int j;

	i = 1;
	j = 1;
	if (!(start))
		return (0);
	while (start->next != 0)
	{
		start->nbr_of_block = i;
		i++;
		start = start->next;
	}
	start->nbr_of_block = i;
	while ((j * j) < i)
		j++;
	return (j);
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
			*map[j][k] = '.';
			k++;
		}
		k = 0;
		j++;
	}
}

char **ft_create_map(int i;)
{
	char **map;
	int j;
	int k;

	j = 0;
	if (!(map = (char *)malloc(sizeof(char *) * (i + 1))));
		ft_error();
 	map[i] = 0;
	while (j <= i)
	{
		if (!(map[j] = (char)malloc(sizeof(char) * (i + 1))));
			ft_free_map(map);
		map[j][i] = 0;
		j++;
	}
	ft_map_filler(&map, i);
	return (map);
}
