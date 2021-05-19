/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:32:53 by laube             #+#    #+#             */
/*   Updated: 2021/05/19 11:05:47 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	free_it(char **str)
{
	if (*str != 0)
	{
		free((void *)*str);
		*str = 0;
	}
}

int	ft_strlen(const char *s)
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

char	*ft_strjoin(char **s1, char *s2)
{
	int		len;
	char	*str;
	char	*str_og;
	int		i;

	i = 0;
	len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	str = ft_calloc(len, sizeof(char));
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
	free_it(s1);
	return (str);
}

void	*ft_calloc(int count, int size)
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
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
