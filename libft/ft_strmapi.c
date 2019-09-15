/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:39:13 by edraco            #+#    #+#             */
/*   Updated: 2019/04/29 16:37:06 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*ret;

	if ((s != 0) && (f != 0))
	{
		i = 0;
		size = 0;
		size = ft_strlen(s);
		ret = ft_memalloc(size + 1);
		if (ret == 0)
			return (0);
		while (i < size)
		{
			ret[i] = f(i, s[i]);
			i++;
		}
		return (ret);
	}
	return (0);
}
