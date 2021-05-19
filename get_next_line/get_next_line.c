/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/05/19 11:07:06 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	norm_killer(int fd, char *buff, int buff_size, int *bytes)
{
	*bytes = read(fd, buff, buff_size);
	buff[*bytes] = 0;
	return (*bytes);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*get_line(char **holder, char **line, char c)
{
	int		i;
	char	*res;
	int		state;

	res = 0;
	i = 0;
	while ((*holder)[i] != c && (*holder)[i] && (*holder)[i] != 0)
		i++;
	*line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while ((*holder)[i] != c && (*holder)[i] && (*holder)[i] != 0)
	{
		(*line)[i] = (*holder)[i];
		i++;
		state = 1;
	}
	if ((*holder)[i + 1] != 0)
	{
		res = ft_strdup(&((*holder)[i + 1]));
	}
	free_it(holder);
	return (res);
}

int	do_holder(char *buff, char **holder, char **line)
{
	*holder = ft_strjoin(holder, buff);
	if (ft_strchr(*holder, '\n'))
	{
		*holder = get_line(holder, line, '\n');
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*holder = NULL;
	int			bytes;

	bytes = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
	{
		if (holder)
			free_it(&holder);
		return (-1);
	}
	if (bytes && !holder)
		holder = ft_calloc(1, 1);
	/*
	if (!buff)
	{
		free_it(&holder);
		return (-1);
	}
	*/
	while (norm_killer(fd, buff, BUFFER_SIZE, &bytes) > 0)
		if (do_holder(buff, &holder, line))
			return (1);
	if (bytes < 0)
	{
		free_it(&holder);
		return (-1);
	}
	if (ft_strchr(holder, '\n'))
	{
		holder = get_line(&holder, line, '\n');
		return (1);
	}
	holder = get_line(&holder, line, '\n');
	free_it(&holder);
	return (0);
}
