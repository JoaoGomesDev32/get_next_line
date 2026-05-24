/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaog <joaog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:05:53 by joaog             #+#    #+#             */
/*   Updated: 2026/05/24 12:25:16 by joaog            ###   ########.fr       */
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
	if (!leftover || !newline[1])
	{
		free(leftover);
		return (NULL);
	}
	rest = ft_strdup(newline + 1);
	free(leftover);
	return rest;
}