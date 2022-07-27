#include "libft.h"

int ft_toupper(int c)
{
	return ('a' <= c && c <= 'z' ? c - 32 : c);
}
