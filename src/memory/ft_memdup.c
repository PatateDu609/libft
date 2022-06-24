#include "libft.h"

uint8_t *ft_memdup(uint8_t *src, size_t len)
{
	uint8_t *dst;

	if (!(dst = malloc(len * sizeof *dst)))
		return (NULL);
	ft_memcpy(dst, src, len);
	return (dst);
}
