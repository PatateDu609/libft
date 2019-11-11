#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	//char **strs = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	char **strs = ft_split("bonjour je suis une bite", 't');
	while (*strs)
		printf("#%s#\n", *strs++);
	return (0);
}
