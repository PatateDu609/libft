/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:47:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/05 18:06:13 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		size;
	char		*s;
	char		*result;

	s = (char *)s1;
	size = ft_strlen(s1);
	while (*s)
		if (ft_strchr(set, *s++))
			size--;
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s = result;
	while (*s1)
		if (!ft_strchr(set, *s1++))
			*s++ = *(s1 - 1);
	*s = 0;
	return (result);
}
