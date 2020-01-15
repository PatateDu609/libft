/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:00:27 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 03:06:55 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				btree_apply_infix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	btree_apply_infix(root->left, f);
	f(root->item);
	btree_apply_infix(root->right, f);
}
