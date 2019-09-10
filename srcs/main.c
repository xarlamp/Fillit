#include "fillit.h"
#include "../libft/libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int	fd;
	t_map *map_start;
	int i;

	i = 0;
	map_start = 0;
	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(EXIT_FAILURE);
	}
	if (valid_or_not(fd = open(av[1], O_RDONLY), &map_start) != 1)
	{
		ft_putstr("Error!\n");
	}
	else
		ft_putstr("All right\n");
	i = ft_count_tetro(map_start);
	printf("Tetro count is: %d\n", i);
	return (0);
}
