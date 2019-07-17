#include "fillit.h"
#include <stdio.h>

t_map		*initialize()
{
	t_map	*new;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(new->line = (char *)malloc(sizeof(char) * BYTEREAD)))
	{
		free(new);
		return (NULL);
	}
	new->nbr_of_block = 1;
	return (new);
}

char		**make_map(char *str)
{
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
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
	ft_putnbr(i);
	ft_putchar('\n');
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

int		valid_or_not(int fd)
{
    int		ret;
    int		retprev;
    t_map	*buf;

	if (fd == -1)
		ft_putstr("Can't open file\n");
	buf = initialize();
	retprev = 0;
	while ((ret = read(fd, buf->line, BYTEREAD)) >= 20)
	{
		if (check_input(buf->line, ret) != 0)
			return (0);
		printf("%s", buf->line);
		buf->nbr_of_block++;
		retprev = ret;
	}
	if (retprev != 20)
		return (0);
	printf("success validation\n");
	return (1);
}
