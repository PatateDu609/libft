#include "ft_getopt.h"
#include "libft.h"
#include <stdio.h>

void print_flags(uint64_t flags, t_option *options)
{
	int i;

	i = 0;
	while (options && options[i].name)
	{
		if (flags & options[i].flag)
			printf(" - %s - %s - %c\n", options[i].name, options[i].description, options[i].short_name);
		i++;
	}
}
