#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	nbr = n < 0 ? -n : n;
	if (n < 0)
	{
		int ls = write(fd, "-", 1);
		(void)ls;
	}
	if (nbr / 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
