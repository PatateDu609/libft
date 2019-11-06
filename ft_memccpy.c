/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:14:03 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/06 22:03:00 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned int	i;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	i = 0;
	while (s[(i ? i - 1 : 0)] != c && i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst + (i ? i : 1));
}
