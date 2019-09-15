/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:05:19 by edraco            #+#    #+#             */
/*   Updated: 2019/09/11 20:45:15 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (!(src) && !(dst))
		return (0);
	if (len != 0)
	{
		if (dst > src)
		{
			while (len-- != 0)
				((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
		else
		{
			while (i < len)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				++i;
			}
		}
	}
	return (dst);
}
