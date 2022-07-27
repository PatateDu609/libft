#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*result;
	size_t	i;

	result = (char*)malloc(size * nitems);
	if (!result)
		return (NULL);
	i = 0;
	while (i < (nitems * size))
		result[i++] = 0;
	return (result);
}
