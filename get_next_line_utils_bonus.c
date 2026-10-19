/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:49:23 by mosmond           #+#    #+#             */
/*   Updated: 2025/11/26 11:11:13 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

char	*ft_strchr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i + 1]);
		i++;
	}
	return (NULL);
}

char	*ft_cleanline(char **line)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	i = 0;
	res = NULL;
	while ((*line)[len] != '\0' && (*line)[len] != '\n')
		len++;
	if ((*line)[0] != '\0')
		res = ft_substr(*line, 0, len + 1);
	if (res != NULL && (*line)[len] != '\0')
	{
		len++;
		while ((*line)[len + i] != '\0')
		{
			(*line)[i] = (*line)[len + i];
			i++;
		}
		(*line)[i] = '\0';
	}
	else
		*line = ft_null(line);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*new;

	i = -1;
	if (!s || s[0] == '\0')
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (++i < len)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}
