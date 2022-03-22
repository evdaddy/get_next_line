/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmerrill <dmerrill@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:12:23 by dmerrill          #+#    #+#             */
/*   Updated: 2022/01/08 13:07:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		n;

	n = 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[n])
	{
		str[n] = s1[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		((unsigned char *)dest)[i]
			= ((const char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2));
	res[size] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	int		min_mem;

	min_mem = len;
	i = 0;
	if (!s || (start >= ft_strlen(s)) || !len)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		min_mem = ft_strlen(s) - start;
	out = (char *)malloc(min_mem + 1);
	if (!out)
		return (NULL);
	while (len && s[start])
	{
		out[i] = s[start + i];
		i++;
		len--;
	}
	out[i] = '\0';
	return (out);
}
