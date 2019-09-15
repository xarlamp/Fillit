/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:54:36 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 13:26:19 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t i_f;

	i = 0;
	if (needle[i] == '\0')
		return (&((char *)haystack)[0]);
	while (haystack[i] && (n > 0))
	{
		if (haystack[i] == needle[0])
		{
			i_f = 0;
			while (haystack[i + i_f] == needle[i_f] && n-- > 0 && needle[i_f] &&
				haystack[i + i_f])
				i_f++;
			if (needle[i_f] == '\0')
				return (&((char *)haystack)[i]);
			n += i_f;
		}
		--n;
		++i;
	}
	return (0);
}
