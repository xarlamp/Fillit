/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:18:50 by edraco            #+#    #+#             */
/*   Updated: 2019/09/14 20:14:23 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void	ft_print_struct(t_map *map_start)
{
	int i;

	i = 0;
	ft_putstr("\n_____DEBUG_____\n");
	while (map_start)
	{
		while (i < 4)
		{
			ft_putstr(map_start->line[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putstr("This is tetro number: ");
		ft_putnbr(map_start->nbr_of_block);
		ft_putstr("\nRibble!\n\n");
		ft_putchar('\n');
		i = 0;
		map_start = map_start->next;
	}
	// while (i < 4)
	// {
	// 	ft_putstr(map_start->line[i]);
	// 	ft_putchar('\n');
	// 	i++;
	// }

	ft_putstr("Ribble-Ribble!\n\n");
	ft_putchar('\n');
}
