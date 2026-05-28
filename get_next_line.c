/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaog <joaog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:16:49 by joagomes          #+#    #+#             */
/*   Updated: 2026/05/28 18:28:14 by joaog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_collect_leftover(int fd, char *leftover)
{
	char	*buffer;
	int		bytes_read;
	char	*joined;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		joined = ft_strjoin(leftover, buffer);
		free(leftover);
		leftover = joined;
		if (ft_strchr(leftover, '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read == -1)
		return (free(leftover), NULL);
	if (!leftover || !leftover[0])
		return (free(leftover), NULL);
	return (leftover);
}

static char	*extract_line(char *leftover)
{
	char	*newline;
	size_t	len;

	if (!leftover || !leftover[0])
		return (NULL);
	newline = ft_strchr(leftover, '\n');
	if (newline)
		len = (newline - leftover) + 1;
	else
		len = ft_strlen(leftover);
	return (ft_substr(leftover, 0, len));
}

static char	*update_leftover(char *leftover)
{
	char	*newline;
	char	*rest;

	newline = ft_strchr(leftover, '\n');
	if (!newline || !newline[1])
	{
		free(leftover);
		return (NULL);
	}
	rest = ft_strdup(newline + 1);
	free(leftover);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_collect_leftover(fd, leftover);
	if (!leftover || !leftover[0])
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	line = extract_line(leftover);
	leftover = update_leftover(leftover);
	return (line);
}
