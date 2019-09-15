/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:18:23 by edraco            #+#    #+#             */
/*   Updated: 2019/04/30 17:19:17 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cur_s1;
	unsigned char *cur_s2;
	unsigned long i;

	i = 0;
	cur_s1 = (unsigned char *)s1;
	cur_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if ((*cur_s1 > *cur_s2) || (*cur_s1 < *cur_s2))
			return (*cur_s1 - *cur_s2);
		i++;
		cur_s1++;
		cur_s2++;
	}
	return (0);
}
