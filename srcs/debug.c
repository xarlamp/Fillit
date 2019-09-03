/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:18:50 by edraco            #+#    #+#             */
/*   Updated: 2019/09/03 16:39:36 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void	ft_print_struct(t_map *map_start)
{
	int i;

	i = 0;
	while (map_start->next != 0)
	{
		while (i < 4)
		{
			ft_putstr(map_start->line[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putstr("Ribble!\n\n");
		ft_putchar('\n');
		i = 0;
		map_start = map_start->next;
	}
	while (i < 4)
	{
		ft_putstr(map_start->line[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("Ribble-Ribble!\n\n");
	ft_putchar('\n');
}
