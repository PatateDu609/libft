/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 03:16:07 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/15 03:17:56 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	btree_apply_by_level(t_btree *root,
		void (*f)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;

}
