#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	char *strr;

	strr = (char *)str + ft_strlen(str);
	while (strr != str && *strr != (char)c)
		strr--;
	return (*strr != (char)c ? NULL : strr);
}
