/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:04:01 by apolleux          #+#    #+#             */
/*   Updated: 2025/12/09 15:25:54 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

/***************************\
*							*
*	Libft functions			*
*							*
\***************************/
size_t	ft_strlen(const char *s);
int		ft_strichr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/***************************\
*							*
*	Get Next Line functions	*
*							*
\***************************/
char	*get_next_line(int fd);

#endif
