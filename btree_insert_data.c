/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:33:12 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 02:12:01 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		btree_insert_child(t_btree *root, void *item,
		int (*cmp)(void *, void *))
{
	if (cmp(root->item, item) <= 0)
	{
		if (root->right)
			btree_insert_child(root->right, item, cmp);
		else
			root->right = btree_create_node(item);
	}
	else
	{
		if (root->left)
			btree_insert_child(root->left, item, cmp);
		else
			root->left = btree_create_node(item);
	}

}

void			btree_insert_data(t_btree **root, void *item,
		int (*cmp)(void *, void *))
{
	if (!root || !cmp)
		return ;
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	else
		btree_insert_child(*root, item, cmp);
}
