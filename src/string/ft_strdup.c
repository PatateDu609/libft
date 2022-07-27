#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i++ < ft_strlen(s1))
		result[i - 1] = s1[i - 1];
	result[i - 1] = 0;
	return (result);
}
