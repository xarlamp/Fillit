/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:13:29 by edraco            #+#    #+#             */
/*   Updated: 2019/04/30 17:18:44 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cur_src;
	unsigned long i;

	i = 0;
	cur_src = (unsigned char *)s;
	while (i < n)
	{
		i++;
		if (*cur_src == (unsigned char)c)
			return (cur_src);
		cur_src++;
	}
	return (0);
}
