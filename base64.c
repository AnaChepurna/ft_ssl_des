#include "ft_ssl_des.h"

void	get_crypt(uint32_t *str, char **crypt, int zero, char *mask)
{
	char	*tmp;
	char	res[5];
	int		i;
	int		n;

	i = 0;
	while (*str  < 16777216)
		*str = *str << 8;
	while (i < 4 - zero)
	{
		n = ((char *)str)[3];
		n = (unsigned char)n >> 2;
		res[i] = mask[n];
		*str = *str << 6;
		i++;
	}
	while (i < 4)
		res[i++] = '=';
	res[4] = '\0';
	tmp = ft_strjoin(*crypt, res);
	free(*crypt);
	*crypt = tmp; 
}

void	encode_base64(char *str, char *mask)
{
	char		pack[4];
	size_t		len;
	size_t		i;
	char		*crypt;
	int			zero;

	len = ft_strlen(str);
	ft_memset(pack, '\0', 4);
	i = 0;
	crypt = ft_strdup("");
	while (i < len)
	{
		zero = len - i > 2 ? 0 : 3 - len + i;
		ft_strncpy(pack, str + i, 3);
		ft_strrev(pack);
		get_crypt((uint32_t *)pack, &crypt, zero, mask);
		ft_memset(pack, '\0', 4);
		i += 3;
	}
	printf("%s\n", crypt);
}

void	get_text(char *str, char **text, char *mask)
{
	char		pack[4];
	uint32_t	res;
	int			i;
	char		*ptr;

	res = 0;
	i = -1;
	while (++i < 4)
	{
		res =  res << 6;
		if ((ptr = ft_strchr(mask, str[i])))
			res += ptr - mask;
	}
	i = -1;
	while (++i < 3)
	{
		ptr = (char *)&res;
		pack[i] = ptr[2 - i];
	}
	pack[3] = '\0';
	ptr = ft_strjoin(*text, pack);
	free(*text);
	*text = ptr;
}

void	decode_base64(char *str, char *mask)
{
	size_t		len;
	size_t		i;
	char		*text;

	len = ft_strlen(str);
	i = 0;
	text = ft_strdup("");
	while (i < len)
	{
		get_text(str + i, &text, mask);
		i += 4;
	}
	printf("%s\n", text);
}

int		main(int c, char **v)
{
	char		*str;
	char		*mask;

	mask = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	get_next_line(0, &str);
	if (ft_strequ(v[1], "-d"))
		decode_base64(str, mask);
	else
		encode_base64(str, mask);
}
