/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:00:30 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 17:27:39 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_exceptions(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				result;
	int				sign;
	long int		sum;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
			*str == '\n' || *str == '\r' || *str == '\f')
		str++;
	sum = 0;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		if ((sum * 10) / 10 != sum)
			return (ft_atoi_exceptions(sign));
		str++;
	}
	result = sign * sum;
	return (result);
}
