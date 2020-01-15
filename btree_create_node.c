/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:54:20 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 00:56:32 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree				*btree_create_node(void *item)
{
	t_btree		*result;

	if (!(result = ((t_btree *)malloc(sizeof(t_btree)))))
		return (NULL);
	result->item = item;
	result->left = NULL;
	result->right = NULL;
	return (result);
}