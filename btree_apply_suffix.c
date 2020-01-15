/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:00:27 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 03:07:09 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				btree_apply_suffix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	btree_apply_suffix(root->left, f);
	btree_apply_suffix(root->right, f);
	f(root->item);
}
