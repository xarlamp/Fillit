/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:11:39 by edraco            #+#    #+#             */
/*   Updated: 2019/09/11 21:09:53 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)haystack - 1;
	if (!*needle)
		return ((char*)haystack);
	i = ft_strlen(needle);
	while (*++s)
		if (ft_strncmp(s, needle, i) == 0)
			return ((char*)s);
	return (NULL);
}
