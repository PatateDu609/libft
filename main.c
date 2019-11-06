#include <stdio.h>
#include "libft.h"

int main ()
{
	t_list *test = ft_lstnew("b");
	test->next = ft_lstnew("c");
	t_list *new = ft_lstnew("a");

	ft_lstadd_front(&test, new);
	ft_lstadd_back(&test, ft_lstnew("d"));

	ft_putstr_fd(ft_lstlast(test)->content, 1);

	free(test);
	return (0);
}
