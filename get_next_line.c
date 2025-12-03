/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:39:14 by apolleux          #+#    #+#             */
/*   Updated: 2025/12/03 19:59:09 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*read_line(int fd, char *stash)
{
	int		read_return;
	char	*result;

	result = NULL;
	while (ft_strichr(stash, '\n') == -1 || ft_strichr(stash, '\0') == -1)
	{
		read_return = read(fd, stash, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(stash);
			stash = NULL;
			return 0;
		}
		result = ft_strjoin(result, stash);
	}
	return(result);
}

char	*border_line(char *stash)
{
	char	*res;

	res = stash;
	if (ft_strichr(stash, '\n'))
		res = ft_substr(stash, 0, ft_strichr(stash, '\n') + 1);
	return res;
}

char	*crystal_line(char *stash)
{
	char	*res;


	return (res);
}

char	*get_next_line(int fd)

{
	static char	*stash;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (0);
	if (!stash)
	{
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		stash = read_line(fd, stash);
	}
	line = border_line(stash);
	// stash =	crystal_line(stash);
	return (line);
}
