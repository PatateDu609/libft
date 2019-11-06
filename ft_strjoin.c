/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:58:07 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/05 17:09:49 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}
