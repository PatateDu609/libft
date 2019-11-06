/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:09:15 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/06 23:14:24 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int		result;

	result = *s++ == c ? 0 : 1;
	while (*s && *(s + 1))
	{
		if (*s == c && *(s + 1) != c)
			result++;
		s++;
	}
	return (result);
}

static int	ft_wordlen(const char *s, char c)
{
	int result;

	result = 0;
	while (*s && *s != c)
	{
		result++;
		s++;
	}
	return (result);
}

static char	*ft_createword(const char *s, char c)
{
	char		*word;
	static int	i = 0;
	int			j;
	int			size;

	j = 0;
	size = ft_wordlen(s + i, c);
	if (!(word = (char *)malloc(size + 1)))
		return (NULL);
	while (j < size)
		word[j++] = s[i++];
	word[j] = 0;
	while (s[i] && s[i] == c)
		i++;
	return (word);
}

char		**ft_split(const char *s, char c)
{
	int		count;
	char	**result;
	int		i;

	count = ft_count_words(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (*s && *s == c)
		s++;
	i = 0;
	while (i < count)
		result[i++] = ft_createword(s, c);
	result[i] = NULL;
	return (result);
}
