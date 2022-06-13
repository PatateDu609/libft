#include "ft_math.h"
#include "libft.h"

static char *bases[] = {
	[2] = "01",
	[8] = "01234567",
	[10] = "0123456789",
	[16] = "0123456789abcdef",
};

int128_t ft_get_int128(int64_t a, uint64_t b)
{
	int128_t n = a;
	n <<= 64;
	n |= b;
	return (n);
}

static size_t ft_uint128len(uint128_t n, int base)
{
	size_t len = 0;

	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char *ft_get_int128_str(int128_t n, int base)
{
	uint8_t sign = n < 0;
	uint128_t abs_n = n < 0 ? -n : n;
	size_t len = ft_uint128len(abs_n, base);
	char *str = ft_calloc(len + sign + 1, sizeof(char));
	char *tmp = str + len + sign;

	if (!str)
		return (NULL);

	if (n < 0)
		*str = '-';
	char *base_set = bases[base];

	while (abs_n != 0)
	{
		*--tmp = base_set[abs_n % base];
		abs_n /= base;
	}
	return (str);
}

uint128_t ft_get_uint128(uint64_t a, uint64_t b)
{
	uint128_t n = a;
	n <<= 64;
	n |= b;
	return (n);
}

char *ft_get_uint128_str(uint128_t n, int base)
{
	size_t len = ft_uint128len(n, base);
	char *str = ft_calloc(len + 1, sizeof(char));
	char *tmp = str + len;

	if (!str)
		return (NULL);

	char *base_set = bases[base];

	while (n != 0)
	{
		*--tmp = base_set[n % base];
		n /= base;
	}
	return (str);
}

int128_t ft_atoi128_base(char *str, int base)
{
	int128_t n = 0;
	int128_t sign = 1;
	char *base_set = bases[base];

	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		char *tmp = ft_strchr(base_set, *str++);
		if (!tmp)
			break;
		n *= base;
		n += tmp - base_set;
	}
	return (n * sign);
}

uint128_t ft_atoui128_base(char *str, int base)
{
	uint128_t n = 0;
	char *base_set = bases[base];

	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str)
	{
		char *tmp = ft_strchr(base_set, *str++);
		if (!tmp)
			break;
		n *= base;
		n += tmp - base_set;
	}
	return (n);
}
