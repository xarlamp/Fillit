/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:08:19 by edraco            #+#    #+#             */
/*   Updated: 2019/09/10 18:38:06 by edraco           ###   ########.fr       */
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
	// if (i = 1)
	// 	start->nbr_of_block = i;
	return (j);
}

char **ft_create_map(t_map *map_start)
