/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaog <joaog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:05:53 by joaog             #+#    #+#             */
/*   Updated: 2026/05/23 13:51:49 by joaog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *letfover)
{
	char	*newline;
	size_t	len;

	if (!letfover || !letfover[0])
		return(NULL);
	newline = ft_strchr(letfover, '\n');
	if (newline)
		len = (newline - letfover) + 1;
	else
		len = ft_strlen(letfover);
	return (ft_substr(letfover, 0, len));
}