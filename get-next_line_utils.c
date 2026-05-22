/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaog <joaog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:17:05 by joaog             #+#    #+#             */
/*   Updated: 2026/05/22 19:17:39 by joaog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

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

	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(len_s1 + len_s2 + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && (len_s1 + 1))
	{
		result[len_s1 + i] = s2[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(char *s)
{
	char	cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = len;
	while (i > 0)
	{
		cpy[len] = s[i];
		i--;
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
	while (s[i] && len + 1)
	{
		ptr = s + start;
		i++;
	}
	ptr = '\0';
	return (ptr);
}
