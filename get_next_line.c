/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:39:14 by apolleux          #+#    #+#             */
/*   Updated: 2025/12/05 15:34:30 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static char	*read_line(int fd, char *stash)
{
	int		read_return ;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (ft_strichr(stash, '\n') == -1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(buffer);
			buffer = NULL;
			return (0);
		}
		else if (read_return == 0)
		{
			free(buffer);
			return (stash);
		}
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*border_line(char *stash)
{
	char	*res;

	res = stash;
	if (ft_strichr(stash, '\n') >= 0)
		res = ft_substr(stash, 0, ft_strichr(stash, '\n') + 1);
	return (res);
}

static char	*dead_line(char *stash)
{
	char	*res;

	res = NULL;
	if (ft_strichr(stash, '\n') >= 0)
		res = ft_substr(stash, ft_strichr(stash, '\n') + 1, ft_strlen(stash));
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	if (!stash)
	{
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		stash = read_line(fd, stash);
	}
	else if (ft_strichr(stash, '\n') == -1)
		stash = read_line(fd, stash);
	line = border_line(stash);
	stash = dead_line(stash);
	return (line);
}
