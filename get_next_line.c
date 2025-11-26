/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:03:58 by apolleux          #+#    #+#             */
/*   Updated: 2025/11/26 17:32:40 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	border_line(char **buffer, char **line)
{
	return ;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			sz;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	sz = read(fd, buffer, BUFFER_SIZE);
	if (!sz)
		return (0);
	if (ft_strchr(buffer, '\n'))
		line = ft_substr(buffer, 0, ft_strchr(buffer, '\n') + 1);
	else
		line = ft_substr(buffer, 0, ft_strlen(buffer));
	if (!line)
		return (0);
	free(buffer);
	return (line);
}

/*====================
VAR :
line = "monde"
static buffer = "\0"

======================
RETURN :
1- bonjour\n
2- monde

======================
FILE :
bonjour\nmonde\0

====================*/
