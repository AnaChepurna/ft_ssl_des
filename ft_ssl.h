#ifndef FT_SSL_H
#define FT_SSL_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>

typedef struct			s_mode
{
	int					mode;
	unsigned long int	key;
	int					ifd;
	int					ofd;
	int					kfd;
}						t_mode;

#endif