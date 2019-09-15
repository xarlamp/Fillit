/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:37:42 by edraco            #+#    #+#             */
/*   Updated: 2019/09/15 22:18:19 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_find_x(char **lfig)
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

int	ft_find_y(char **lfig)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (lfig[i][j] == '#')
				return(j);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_find_x_end(char **lfig)
{
	int i;
	int j;

	i = 4;
	while (i > 0)
	{
		j = 4;
		while (j > 0)
		{
			if (lfig[i - 1][j - 1] == '#')
				return(i - 1);
			j--;
		}
		i--;
	}
	return (0);
}

int	ft_find_y_end(char **lfig)
{
	int i;
	int j;

	j = 4;
	while (j > 0)
	{
		i = 4;
		while (i > 0)
		{
			if (lfig[i - 1][j - 1] == '#')
				return(j - 1);
			i--;
		}
		j--;
	}
	return (0);
}
