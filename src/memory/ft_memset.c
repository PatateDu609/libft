#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char*)b;
	i = 0;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (str);
}
