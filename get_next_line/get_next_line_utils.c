/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:32:53 by laube             #+#    #+#             */
/*   Updated: 2021/05/16 17:17:14 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	str = malloc(len * sizeof(char));
	str_og = str;
	if (!str)
		return (NULL);
	while ((*s1)[i])
	{
		*str_og = (*s1)[i++];
		str_og++;
	}
	while (*s2)
	{
		*str_og = *s2;
		s2++;
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