/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sider.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:30:45 by edraco            #+#    #+#             */
/*   Updated: 2019/09/15 19:37:12 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_x(char **lfig)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			// ft_putstr("i = ");
			// ft_putnbrendl(i);
			// ft_putstr("j = ");
			// ft_putnbrendl(j);
			if (lfig[i][j] == '#')
				return(j);
			// ft_putstr("Debug 2.1\n");
			i++;
		}
		j++;
	}
	return (0);
}

static char **ft_sider_worker(char **line)
{
	int x;
	int y;

	x = ft_find_x(line);
	y = ft_find_y(line);

}

static void ft_free_figure(char **line)
{
	char **ptr;

	ptr = line;
	while (ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(ptr);
}

void	ft_sider(t_map *map_start)
{
	char **ptr;
	while (map_start)
	{
		ptr = map_start->line;
		map_start->line = ft_sider_worker(map_start->line);
		ft_free_figure(ptr);
		map_start = map_start->next;
	}
}
