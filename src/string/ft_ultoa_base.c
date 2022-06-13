#include "libft.h"
#include <inttypes.h>

static size_t ft_intlen(uint64_t n, int base)
{
	size_t len = 0;

	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char *ft_ultoa_base(uint64_t val, int base)
{
	char *res;
	char *base_set[] = {
		[2] = "01",
		[8] = "01234567",
		[10] = "0123456789",
		[16] = "0123456789abcdef"};
	size_t len;

	if (base < 2 || base > 16 || !base_set[base])
	{
		fprintf(stderr, "ft_ultoa_base: Invalid base %d\n", base);
		return (NULL);
	}

	len = ft_intlen(val, base);
	if (!(res = ft_calloc(len + 1, sizeof(char))))
		return (NULL);

	if (val == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	while (val)
	{
		res[--len] = base_set[base][val % base];
		val /= base;
	}
	return res;
}
