/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:03:58 by apolleux          #+#    #+#             */
/*   Updated: 2025/11/25 17:12:00 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	free_line(char *line)
// {
// 	free(line);
// }

static void	border_line(char **buffer)
{
	int		len;
	int		index;
	char	*tmp;

	len = ft_strlen(*buffer);
	index = ft_strchr(*buffer, '\n');
	if (index)
	{
		tmp = ft_substr(*buffer, index-1, len - index-1);
		free(*buffer);
		*buffer = tmp;
	}
}


char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	int			sz;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	tmp = buffer;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	sz = read(fd, buffer, BUFFER_SIZE);
	if (!sz)
		return (0);
	line = buffer;
	// free(buffer);
	if (!line)
		return (0);
	border_line(&buffer);
	return (buffer);
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


// rld!0
