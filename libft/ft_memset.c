/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:47:31 by edraco            #+#    #+#             */
/*   Updated: 2019/04/30 17:17:27 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char *ptr;

	ptr = (unsigned char *)memptr;
	while (num > 0)
	{
		*ptr = (char)val;
		num--;
		ptr++;
	}
	return (memptr);
}
