#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		if (str[i++] == (unsigned char)c)
			return (str + i - 1);
	}
	return (NULL);
}
