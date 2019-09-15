/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:39:20 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 13:25:48 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if ((s1 == 0) || (s2 == 0))
		return (0);
	while ((s1[i] != 0) && (s2[i] != 0) && (i < n))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if ((i == n) && (s1[i - 1] == s2[i - 1]))
		return (1);
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
