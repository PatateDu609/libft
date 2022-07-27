#include "libft.h"

#ifdef __LP64__

size_t	ft_strlen(const char *str)
{
	if (!str)
		return (0);

	const uint64_t *ptr = (const uint64_t *)str;

	size_t len = 0;
	for (;;)
	{
		if ((*ptr & 0xff) == 0)
			return len;
		if ((*ptr & 0xff00) == 0)
			return len + 1;
		if ((*ptr & 0xff0000) == 0)
			return len + 2;
		if ((*ptr & 0xff000000) == 0)
			return len + 3;
		if ((*ptr & 0xff00000000) == 0)
			return len + 4;
		if ((*ptr & 0xff0000000000) == 0)
			return len + 5;
		if ((*ptr & 0xff000000000000) == 0)
			return len + 6;
		if ((*ptr & 0xff00000000000000) == 0)
			return len + 7;
		ptr++, len += 8;
	}
	return len;
}

#elif defined __LP32__

size_t ft_strlen(const char *str)
{
	if (!str)
		return (0);

	const uint32_t *ptr = (const uint32_t *)str;

	size_t len = 0;
	for (; *ptr; )
	{
		if ((*ptr & 0xff) == 0)
			return len;
		if ((*ptr & 0xff00) == 0)
			return len + 1;
		if ((*ptr & 0xff0000) == 0)
			return len + 2;
		if ((*ptr & 0xff000000) == 0)
			return len + 3;
		len += 4;
		ptr += 4;
	}
	return len;
}

#else // Unknown architecture: we use the slow way

size_t ft_strlen(const char *str)
{
	if (!str)
		return (0);

	size_t len = 0;
	for (; *str; str++)
		len++;
	return (len);
}

#endif
