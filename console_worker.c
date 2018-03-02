#include "ft_ssl.h"

void	print_usage(void)
{
	printf("usage: ft_ssl command [command opts] [command args]\n");
}

void	print_info(void)
{
	printf("Standard commands:\n\n\
		Message Digest commands:\n\n\
		Cipher commands:\n\
		base64\n\
		des\n\
		des-ecb\n\
		des-cbc\n");
}

void	read_console(char *msg, int (*handler)(char *arg))
{
	char	*str;

	printf("%s: ", msg);
	if (get_next_line(0, &str) > 0)
	{
		if (!(*handler(str)))
		{
			print_info();
			read_console(msg, handler);
		}
		free(str);
	}
}