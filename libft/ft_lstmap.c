/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraco <edraco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:37:37 by edraco            #+#    #+#             */
/*   Updated: 2019/04/30 18:03:45 by edraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *str, size_t n)
{
	unsigned char	*ptr;
	int				val;

	n = 0;
	val = 0;
	ptr = (unsigned char *)str;
	while (n > 0)
	{
		*ptr = (char)val;
		n--;
		ptr++;
	}
	free(str);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;

	if (lst)
	{
		result = (t_list *)(malloc(sizeof(t_list)));
		if (result)
		{
			result = f(lst);
			if (lst->next)
			{
				result->next = ft_lstmap(lst->next, f);
				if (result->next == 0)
				{
					ft_lstdel(&result, ft_del);
					return (0);
				}
			}
			return (result);
		}
	}
	return (0);
}
