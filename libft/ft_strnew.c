/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:01:31 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 13:40:02 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	++size;
	mem = (char *)(malloc(sizeof(char) * (size)));
	if (mem)
	{
		while (i < size)
			mem[i++] = '\0';
		return (mem);
	}
	return (0);
}
