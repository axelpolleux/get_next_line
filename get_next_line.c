/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:39:14 by apolleux          #+#    #+#             */
/*   Updated: 2025/11/28 22:30:25 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

// void	col_line(char **line, char **buffer)
// {

// }

void	border_line(char **line, char **buffer)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_substr(*buffer, 0, ft_strchr(*buffer, '\n'));
	tmp2 = *buffer;
	*line = ft_strjoin(*line, tmp1);
	*buffer = ft_substr(tmp2, ft_strchr(tmp2, '\n') + 1, ft_strlen(tmp2));
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			sz;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	line = "";
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (0);
	}
	else {
		line = ft_strjoin(buffer, line);
	}
	line = ft_substr(buffer, 0, ft_strlen(buffer));
	while ((ft_strchr(buffer, '\n') == -1) || (ft_strchr(buffer, '\0') == -1))
	{
		sz = read(fd, buffer, BUFFER_SIZE);
		if (!sz)
			return (0);
		if ((ft_strchr(buffer, '\n') == -1) || (ft_strchr(buffer, '\0') == -1))
			line = ft_strjoin(line, buffer);
	}
	if (ft_strchr(buffer, '\n'))
		border_line(&line, &buffer);

	line[ft_strlen(line)] = '\n';
	return (line);
}
