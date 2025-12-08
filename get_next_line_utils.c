/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:03:55 by apolleux          #+#    #+#             */
/*   Updated: 2025/12/08 17:14:32 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (*s != (char)c && *s)
	{
		s++;
		i++;
	}
	if (*s == (char)c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
	{
		res = ft_substr(s2, 0, ft_strlen(s2));
		return (res);
	}
	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	free((void *)s1);
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (0);
	i = 0;
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (i < (size * nmemb))
	{
		res[i] = '\0';
		i++;
	}
	return ((void *)res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			copy_len;
	char			*res;
	size_t			i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		res = (char *)ft_calloc(1, 1);
		return (res);
	}
	copy_len = ft_strlen(s) - start;
	if (len < copy_len)
		copy_len = len;
	res = (char *)ft_calloc(copy_len + 1, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < copy_len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
