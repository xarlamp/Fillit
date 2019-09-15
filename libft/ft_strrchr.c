/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:08:08 by edraco            #+#    #+#             */
/*   Updated: 2019/04/17 10:39:48 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*str;
	char	*ret;

	ret = 0;
	str = (char *)s;
	ch = (char)c;
	while (*str != 0)
	{
		if (*str == ch)
			ret = str;
		str++;
	}
	if (ch == 0)
		return (str);
	if (ret != 0)
		return (ret);
	return (0);
}
