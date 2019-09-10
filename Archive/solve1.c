/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:54:02 by edraco            #+#    #+#             */
/*   Updated: 2019/07/19 16:31:07 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_solver(char ***tetro_list)
{
	int tetrocount;
	char **map;

	tetrocount = 0;
	while (tetro_list[tetrocount])
		tetrocount++;
	ft_map_regen(&map, ft_sqrt(tetrocount * 4));
	ft_placetry(map, tetro_list);
}

void	ft_map_regen(char ***map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*map != 0)
	{
		while (*map[i])
		{
			free(*map[i]);
			i++;
		}
		free(*map);
	}
	i = 0;
	*map = (char **)malloc(sizeof(char *) * (size + 1));
	*map[size] = 0;
	while (i < size)
	{
		*map[i] = ft_strmap(size + 1));
		i++;
	}
}

char	*ft_strmap(int size)
{
	char *ptr;
	int i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * size);
	while (i < size)
	{
		ptr[i] = '.';
		i++;
	}
	ptr[size] = '\0';
	return (ptr);
}

int		ft_sqrt(int num)
{
	int i;

	i = 0;
	while (i * i < num)
		i++;
	return (i);
}
