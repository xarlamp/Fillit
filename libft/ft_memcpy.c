/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:25:52 by edraco            #+#    #+#             */
/*   Updated: 2019/04/30 17:41:55 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *cur_src;
	unsigned char *cur_dst;
	unsigned long i;

	if (dst == src)
		return ((void *)0);
	i = 0;
	cur_src = (unsigned char *)src;
	cur_dst = (unsigned char *)dst;
	while (i < n)
	{
		*cur_dst = (char)*cur_src;
		i++;
		cur_src++;
		cur_dst++;
	}
	return (dst);
}
