/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:08:19 by edraco            #+#    #+#             */
/*   Updated: 2019/09/11 19:02:58 by edraco           ###   ########.fr       */
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
	while ((j * j) < i * 4)
		j++;
	return (j);
}

void 	ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
