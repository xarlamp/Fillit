/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:39:31 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 13:26:52 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		i = 0;
		str = 0;
		str = (char *)ft_memalloc(sizeof(char) * (len + 1));
		if (str == 0)
			return (0);
		if (str == 0)
			return (0);
		while (i + start < len + start)
		{
			str[i] = s[i + start];
			i++;
		}
		return (str);
	}
	return (0);
}
