#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	result;

	i = 0;
	while (i < dstsize && dst[i])
		i++;
	result = i + ft_strlen(src);
	if (dstsize <= i)
		return (result);
	ft_strlcpy(dst + i, src, dstsize - i);
	return (result);
}
