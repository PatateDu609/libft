#include <stdio.h>
#include "libft.h"

void del(void *d)
{
	(void)d;
}

int main ()
{
	t_list *test = ft_lstnew("b");
	test->next = ft_lstnew("c");
	t_list *new = ft_lstnew("a");

	ft_lstadd_front(&test, new);
	ft_lstadd_back(&test, ft_lstnew("d"));
	
	new = test->next;
	ft_lstdelone(test, del);
	test = new;
	ft_putendl_fd(ft_lstlast(test)->content, 1);

	free(test);
	return (0);
}
