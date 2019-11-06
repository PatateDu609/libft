/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:34:38 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/06 23:13:59 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int n)
{
	static int	size = 0;

	if (n == 0 && !size)
		return (1);
	else if (n == 0)
		return (size);
	size++;
	return (ft_size(n / 10));
}

char		*ft_itoa(int n)
{
	char			*result;
	int				size;
	unsigned int	nbr;

	nbr = (n < 0) ? -n : n;
	size = ((n < 0) ? 1 : 0) + ft_size(nbr);
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	result[size] = 0;
	while (size-- > 1)
	{
		result[size] = '0' + nbr % 10;
		nbr /= 10;
	}
	if (n >= 0)
		result[0] = nbr + '0';
	return (result);
}
