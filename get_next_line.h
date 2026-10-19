/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:17 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/01 15:31:29 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_null(char **line);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s);
char	*ft_cleanline(char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif