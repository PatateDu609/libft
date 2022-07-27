#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned int	i;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
