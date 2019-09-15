/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:39:43 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 13:27:40 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*chars_only(void)
{
	char *new;

	new = (char *)(malloc(sizeof(char) * 1));
	if (new)
	{
		*new = '\0';
		return (new);
	}
	return (0);
}

static char	*not_chars_only(size_t j, size_t i, char const *s)
{
	char	*new;
	size_t	n;

	n = 0;
	new = (char *)(malloc(sizeof(char) * (ft_strlen(s) - j + 1)));
	if (new)
	{
		while (n < (ft_strlen(s) - j))
			new[n++] = s[i++];
		new[n] = '\0';
		return (new);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		if (ft_strlen(s) == i)
			return (chars_only());
		else
		{
			while (s[ft_strlen(s) - 1 - j] == '\n' || s[ft_strlen(s) - 1 - j]
			== ' ' || s[ft_strlen(s) - 1 - j] == '\t')
				j++;
			j += i;
			return (not_chars_only(j, i, s));
		}
		return ((char *)s);
	}
	return (0);
}
