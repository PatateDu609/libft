/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 02:45:52 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 03:01:02 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	btree_height(t_btree *root, int level)
{
	if (root->left)
		return (btree_height(root->left, level + 1));
	else if (root->right)
		return (btree_height(root->right, level + 1));
	else
		return (level);
}

int			btree_level_count(t_btree *root)
{
	if (!root)
		return (-1);
	else if (!root->left && !root->right)
		return (0);
	else
		return (btree_height(root, 1));
}
