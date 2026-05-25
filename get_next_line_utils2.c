/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagomes <joagomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:05:53 by joaog             #+#    #+#             */
/*   Updated: 2026/05/25 14:39:38 by joagomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *letfover)
{
	char	*newline;
	size_t	len;

	if (!letfover || !letfover[0])
		return (NULL);
	newline = ft_strchr(letfover, '\n');
	if (newline)
		len = (newline - letfover) + 1;
	else
		len = ft_strlen(letfover);
	return (ft_substr(letfover, 0, len));
}

char	*update_leftover(char *leftover)
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

char	*read_collect_leftover(int fd, char *leftover)
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
	{
		free(leftover);
		return (NULL);
	}
	return (leftover);
}
