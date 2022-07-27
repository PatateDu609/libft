#include "libft.h"

int ft_tolower(int c)
{
	return ('A' <= c && c <= 'Z' ? c + 32 : c);
}
