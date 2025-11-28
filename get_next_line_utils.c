/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:03:55 by apolleux          #+#    #+#             */
/*   Updated: 2025/11/28 22:26:19 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
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

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
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
	// else if (copy_len == 0)
	// 	return (0);
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
