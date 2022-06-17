#include "libft.h"

uint8_t *ft_memjoin(uint8_t *src1, size_t len1, uint8_t *src2, size_t len2)
{
	uint8_t *dst;

	if (!(dst = malloc(len1 + len2)))
		return (NULL);
	ft_memcpy(dst, src1, len1);
	ft_memcpy(dst + len1, src2, len2);
	free(src1);
	return (dst);
}
