/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:08:19 by edraco            #+#    #+#             */
/*   Updated: 2019/08/30 12:11:48 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *ft_charset(int size)
{
	char *current_buf;
	int i;

	i = 0;
	current_buf = (char *)malloc(sizeof(char) * size);
	while (i < size - 1)
	{
		current_buf[i] = '!';
		i++;
	}
	current_buf[i] = '\0';
	return (current_buf);
}
