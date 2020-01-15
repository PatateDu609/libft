/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:33:50 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 02:45:08 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmp)(void *, void *))
{
	if (!root)
		return (NULL);
	else if (cmp(root->item, data_ref) == 0)
		return (root->item);
	else if (cmp(root->item, data_ref) > 0)
		return (btree_search_item(root->left, data_ref, cmp));
	else if (cmp(root->item, data_ref) < 0)
		return (btree_search_item(root->right, data_ref, cmp));
	else
		return (NULL);
}
