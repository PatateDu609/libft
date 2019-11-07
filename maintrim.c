#include <stdio.h>
#include "libft.h"

int main(int ac, char **av)
{
	(void)ac;
	char *trimed = ft_strtrim(av[1], av[2]);
	printf("#%s#\n", trimed);
	free(trimed);
	return (0);
}
