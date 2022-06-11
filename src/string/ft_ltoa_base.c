#include "libft.h"

static size_t ft_intlen(int n, int base)
{
	size_t len = 0;

	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char *ft_ltoa_base(int64_t val, int base)
{
	char *res;
	char *base_set[] = {
		[2] = "01",
		[8] = "01234567",
		[10] = "0123456789",
		[16] = "0123456789abcdef"};

	if (base < 2 || base > 16 || !base_set[base])
		return (NULL);

	if (val < 0)
	{
		val = -val;
		if (!(res = ft_strnew(ft_intlen(val, base) + 1)))
			return (NULL);
		res[0] = '-';
	}
	else
	{
		if (!(res = ft_strnew(ft_intlen(val, base))))
			return (NULL);
	}

	return res;
}
