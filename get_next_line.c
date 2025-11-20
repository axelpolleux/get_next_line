/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:03:58 by apolleux          #+#    #+#             */
/*   Updated: 2025/11/20 18:08:08 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

// void	free_line(char *line)
// {
// 	free(line);
// }

// char	*read_line(int fd, char *buffer)
// {
// 	return (0);
// }

char *get_next_line(int fd)
{
	static char	*buffer;
	int			sz;

	if (fd <= 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(1028);
	sz = read(fd, buffer, 5);
	if (!sz)
		return (0);
	buffer[sz] = '\0';
	return (buffer);
}


