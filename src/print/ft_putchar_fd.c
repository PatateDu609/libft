#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	int ls = write(fd, &c, 1);
	(void)ls;
}
