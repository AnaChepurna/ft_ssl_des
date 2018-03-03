#include "ft_ssl.h"

char	*read_pass(int fd)
{
	char	*str;

	if (!fd)
		ft_putstr("enter des key in hex: ");
	get_next_line(fd, &str);
	return (str);
}

char	*read_data(int fd)
{
	
}