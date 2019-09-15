/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:47:53 by edraco            #+#    #+#             */
/*   Updated: 2019/04/13 19:51:47 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)malloc(size);
	i = 0;
	if (mem != 0)
	{
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
		return ((void *)mem);
	}
	return (0);
}
