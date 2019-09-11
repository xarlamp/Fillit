/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:48:51 by edraco            #+#    #+#             */
/*   Updated: 2019/09/11 19:03:16 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void 	ft_pre_solver(t_map *map_start)
{
	char **map;

	map = ft_create_map(ft_count_tetro(map_start));
	ft_print_map(map);

}
