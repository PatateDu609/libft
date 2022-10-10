#include "libft.h"

char *ft_strndup(const char *s1, size_t n)
{
	char *ret;
	size_t len;

	len = ft_strlen(s1);
	if (n > len)
		n = len;
	if (!(ret = ft_calloc(n + 1, sizeof *ret)))
		return (NULL);
	ft_strlcpy(ret, s1, n + 1);
	return (ret);
}
