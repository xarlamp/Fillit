
#ifndef FILLIT_H
# define FILLIT_H

// # include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BYTEREAD 21
# define BLOCK '#'
# define SPACE '.'

int			valid_or_not(int fd);

typedef struct		s_map
{
	char		*line;
	int		nbr_of_block;

}			t_map;

#endif
