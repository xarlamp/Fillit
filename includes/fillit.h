
#ifndef FILLIT_H
# define FILLIT_H

//FOR THE GODS SAKE DELETE IT!!!!!!
#include <stdio.h>
//


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BYTEREAD 21
# define BLOCK '#'
# define SPACE '.'



typedef struct		s_map
{
	char			**line;
	int				nbr_of_block;
	struct s_map	*next;

}					t_map;

int				valid_or_not(int fd, t_map **map_start);
char 			*ft_charset(int size);
void	ft_print_struct(t_map *map_start);
int		ft_count_tetro(t_map *start);
void 	ft_pre_solver(t_map *map_start);
char **ft_create_map(t_map *map_start);


#endif
