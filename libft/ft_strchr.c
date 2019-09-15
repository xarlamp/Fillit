/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:58:23 by edraco            #+#    #+#             */
/*   Updated: 2019/04/30 17:20:57 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;

	str = (char *)s;
	ch = (char)c;
	while (*str != 0)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (ch == 0)
		return (str);
	return (0);
}
