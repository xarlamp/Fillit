#include <stdio.h>
#include "fillit.h"
#include "../libft/libft.h"

t_map	*ft_transform(char *buf)
{
	int i;
	t_map *elem;
	char **tline;

	i = 0;
	tline = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		tline[i] = (char *)malloc(sizeof(char) * 5);
		tline[i][5] = 0;
		i++;
	}
	tline[5] = 0;
	i = 1;
	while (i < 21)
	{
		if (i % 5)
			tline[i / 5][(i % 5) - 1] = buf[i - 1];
		i++;
	}
	elem = (t_map *)malloc(sizeof(t_map));
	elem->line = tline;
	elem->next = 0;
	return (elem);
}


void	ft_fill_block(t_map **map_start, char *buf)
{
	t_map *map_ptr;
	t_map *map_prev_ptr;
	int flag;

	map_ptr = 0;
	map_prev_ptr = 0;
	flag = 0;
	if (*map_start == 0)
		*map_start = ft_transform(buf);
	else
	{
		map_ptr = *map_start;
		while (map_ptr->next != 0)
		{
			map_prev_ptr = map_ptr;
			map_ptr = map_ptr->next;
			flag = 1;
		}
		if (flag)
			map_prev_ptr->next = map_ptr;
		map_ptr->next = ft_transform(buf);
	}
}

int		check_block(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == BLOCK)
		{
			if (*(str + 1) == BLOCK)
				i++;
			if (*(str - 1) == BLOCK)
				i++;
			if (*(str + 5) == BLOCK)
				i++;
			if (*(str - 5) == BLOCK)
				i++;
		}
		str++;
	}
	// ft_putnbr(i);
	// ft_putchar('\n');
	return (i == 6 || i == 8);
}

int		check_input(char *str, int ret)
{
	int	i;
	int	block;

	i = 0;
	block = 0;

	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == BLOCK || str[i] == SPACE))
				return (1);
			if (str[i] == BLOCK && ++block > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (ret == 21 && str[20] != '\n')
		return (4);
	if(!(check_block(str)))
		return (5);
	return (0);
}

int		valid_or_not(int fd, t_map **map_start)
{
	int ret;
	int retprev;
	char *buf;

	if (fd == -1)
	{
		ft_putstr("Can't open file\n");
		return (-1);
	}
	retprev = 0;
	buf = ft_charset(22);
	while ((ret = read(fd, buf, BYTEREAD)) >= 20)
	{
		if (check_input(buf, ret) != 0)
			return(-1);
		printf("%s", buf);

		ft_fill_block(map_start, buf);
		//buf->nbr_of_block++;
		retprev = ret;
	}
	if (retprev != 20)
		return (1);
	ft_putstr("DEBUG LINE\n\n");
	ft_print_struct(*map_start);
	ft_putstr("success validation\n");
	return (1);
}
