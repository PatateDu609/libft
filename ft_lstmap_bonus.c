/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:35:58 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/10 21:14:32 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_start;

	if (!lst)
		return (NULL);
	if (!(result = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	result_start = result;
	while (lst)
	{
		if (!(result->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result_start, del);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	return (result_start);
}
