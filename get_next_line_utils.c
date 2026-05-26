/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaog <joaog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:17:05 by joaog             #+#    #+#             */
/*   Updated: 2026/05/26 20:54:18 by joaog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;
	int		i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(len_s1 + len_s2 + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
		result[len_s1 + i] = s2[i];
	result[len_s1 + len_s2] = '\0';
	return (result);
}

char	*ft_strdup(char *s)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
