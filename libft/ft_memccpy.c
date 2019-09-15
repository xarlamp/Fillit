/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:52:37 by edraco            #+#    #+#             */
/*   Updated: 2019/04/30 17:18:24 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *cur_src;
	unsigned char *cur_dst;
	unsigned long i;

	i = 0;
	cur_src = (unsigned char *)src;
	cur_dst = (unsigned char *)dst;
	while (i < n)
	{
		*cur_dst = (char)*cur_src;
		i++;
		cur_dst++;
		if (*cur_src == (unsigned char)c)
			return (cur_dst);
		cur_src++;
	}
	return (0);
}
