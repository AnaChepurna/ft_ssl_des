#include "ft_ssl.h"

void	print_usage(char *program);
{
	ft_putstr("usage: ");
	ft_putstr(program);
	ft_putstr(" command [command opts] [command args]\n");
	exit(1);
}

void	print_commands(char *program, char *invalid_command)
{
	ft_putstr(program);
	ft_putstr(":Error: '");
	ft_putstr(invalid_command);
	ft_putstr("' is an invalid command.\n\n");
	ft_putstr("Standard commands:\n\nMessage Digest commands:\n\n");
	ft_putstr("Cipher commands:\nbase64\ndes\ndes-ecb\ndes-cbc\n");
	exit(1);
}

void	print_options(void)
{
	ft_putstr("options are\n");
	exit(1);
}