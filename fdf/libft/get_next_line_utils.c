/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:32:53 by laube             #+#    #+#             */
/*   Updated: 2021/06/19 13:46:52 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_free_it(char **str, int bytes)
{
	if (*str != 0)
	{
		free((void *)*str);
		*str = 0;
	}
	if (bytes < 0)
		return (-1);
	if (bytes == 0)
		return (0);
	return (0);
}

int	gnl_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char **s1, char *s2)
{
	int		len;
	char	*str;
	char	*str_og;
	int		i;

	i = 0;
	len = gnl_strlen(*s1) + gnl_strlen(s2) + 1;
	str = gnl_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	str_og = str;
	while ((*s1)[i])
	{
		*str_og = (*s1)[i++];
		str_og++;
	}
	i = 0;
	while (s2[i])
	{
		*str_og = s2[i++];
		str_og++;
	}
	*str_og = '\0';
	gnl_free_it(s1, 0);
	return (str);
}

void	*gnl_calloc(int count, int size)
{
	void		*pointing;
	int			i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	i = 0;
	pointing = malloc(size * count);
	if (!pointing)
		return (0);
	while (i < (size * count))
		((char *)pointing)[i++] = 0;
	return (pointing);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
