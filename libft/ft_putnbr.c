/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:38:31 by edraco            #+#    #+#             */
/*   Updated: 2019/04/28 13:23:58 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int cnt;

	cnt = 1;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb / cnt / 10 >= 1)
		cnt = cnt * 10;
	while (cnt >= 1)
	{
		ft_putchar('0' + nb / cnt % 10);
		cnt = cnt / 10;
	}
}
