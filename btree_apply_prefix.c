/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:00:27 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 01:08:37 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				btree_apply_prefix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	f(root->item);
	btree_apply_prefix(root->left, f);
	btree_apply_prefix(root->right, f);
}
