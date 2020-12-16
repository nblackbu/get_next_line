/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:51:52 by nblackbu          #+#    #+#             */
/*   Updated: 2020/12/12 16:58:48 by nblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst)
		return (0);
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	if (!str)
		return (NULL);
	s = (char *)str;
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return (s);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (0);
	ft_strlcpy(s2, s1, (i + 1));
	return (s2);
}
