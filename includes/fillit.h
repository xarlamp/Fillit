
#ifndef FILLIT_H
# define FILLIT_H

// # include "libft.h"
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

#endif
