#include "ft_ssl.h"

void	init_options(t_opt *opt)
{
	(*opt).mode = 0;
	(*opt).key = 0;
	(*opt).ifd = 0;
	(*opt).ofd = 1;
	(*opt).kfd = 0;
}

void	handle_command()