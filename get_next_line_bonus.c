/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:39:14 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/09 10:40:37 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			break ;
		buffer[read_return] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*border_line(char *stash)
{
	char	*res;
	int		nl_idx;

	res = NULL;
	if (!stash)
		return (0);
	nl_idx = ft_strichr(stash, '\n');
	if (nl_idx >= 0)
		res = ft_substr(stash, 0, nl_idx);
	else
		res = ft_substr(stash, 0, ft_strlen(stash));
	return (res);
}

static char	*dead_line(char *stash)
{
	char	*res;

	res = NULL;
	if (!stash)
		return (0);
	if (ft_strichr(stash, '\n') >= 0)
		res = ft_substr(stash, ft_strichr(stash, '\n') + 1,
				(ft_strlen(stash) - ft_strichr(stash, '\n') + 1));
	free(stash);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	if (ft_strichr(stash[fd], '\n') == -1)
		stash[fd] = read_line(fd, stash[fd]);
	line = border_line(stash[fd]);
	stash[fd] = dead_line(stash[fd]);
	if (stash[fd] && stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
