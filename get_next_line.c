/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:39:14 by apolleux          #+#    #+#             */
/*   Updated: 2025/12/01 11:42:33 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)

{
	static char	*buffer;
	char		*line;
	int			read_return;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_strchr(buffer, '\n') == -1 || ft_strchr(buffer, '\0') == -1)
	{
		if (ft_strchr(buffer, '\n') == -1 || ft_strchr(buffer, '\0') == -1)
		{
			read_return = read(fd, buffer, BUFFER_SIZE);
			if (read_return <= 0)
			{
				free(buffer);
				buffer = NULL;
				return (0);
			}
		}
	}
	if (ft_strchr(buffer, '\n'))
		line = ft_substr(buffer, 0, ft_strchr(buffer, '\n'));
	return (line);
}
