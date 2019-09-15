/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:39:27 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 12:39:54 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t result;

	result = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
			++result;
		while (*s && *s != c)
			++s;
	}
	return (result);
}

static void		clean_all(char ***new, size_t i)
{
	while (i-- > 0)
	{
		free(new[i]);
		new[i] = 0;
	}
	free(new);
	new = 0;
}

static char		*create_word(char const *s, char c, char **new, size_t i)
{
	size_t	letters;
	char	*word;

	letters = 0;
	while (s[letters] != c && s[letters])
		++letters;
	word = (char *)(malloc(sizeof(char) * (letters + 1)));
	if (word != 0)
	{
		while (*s && *s != c)
		{
			*word = (char)(*s);
			++word;
			++s;
		}
		*word = '\0';
		word -= letters;
		return (word);
	}
	clean_all(&new, i);
	return (0);
}

static char		**create_array(char const *s, char c, char **new, size_t i)
{
	size_t j;

	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			++j;
		if (s[j] && s[j] != c)
			new[i] = create_word(&s[j], c, new, i);
		if (!&new[i])
			return (0);
		++i;
		while (s[j] && s[j] != c)
			++j;
	}
	new[count_words(s, c)] = 0;
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;

	if (s)
	{
		i = 0;
		new = (char **)(malloc(sizeof(char *) * (count_words(s, c) + 1)));
		if (new)
		{
			return (create_array(s, c, new, i));
		}
	}
	return (0);
}
