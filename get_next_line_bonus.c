/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:49:19 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/02 12:53:31 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_null(char **line)
{
	free(*line);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	if (!line[fd])
		line[fd] = ft_strdup("");
	if (!line[fd])
		return (free(buffer), NULL);
	while (bytes > 0 && !ft_strchr(line[fd]))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), line[fd] = ft_null(&line[fd]), NULL);
		buffer[bytes] = '\0';
		line[fd] = ft_strjoin(line[fd], buffer);
		if (!line[fd])
			return (free(buffer), NULL);
	}
	return (free(buffer), ft_cleanline(&line[fd]));
}

// int	main(void)
// {
// 	int		i = 0;
// 	int		fd;
// 	int		fd2;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	fd2 = open("text2.txt", O_RDONLY);
// 	if (fd2 == -1)
// 		return (1);
// 	while (i < 20)
// 	{
// 		line = get_next_line(fd);
// 		printf("<%s>", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("<%s>", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	close(fd2);
// 	return (0);
// }
