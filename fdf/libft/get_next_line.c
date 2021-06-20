/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/06/19 13:46:34 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	res = gnl_calloc((gnl_strlen(s1) + 1), sizeof(char));
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

	res = 0;
	i = 0;
	while ((*holder)[i] != c && (*holder)[i] && (*holder)[i] != 0)
		i++;
	*line = gnl_calloc(i + 1, sizeof(char));
	i = 0;
	while ((*holder)[i] != c && (*holder)[i] && (*holder)[i] != 0)
	{
		(*line)[i] = (*holder)[i];
		i++;
	}
	if ((*holder)[i + 1] != 0)
	{
		res = ft_strdup(&((*holder)[i + 1]));
	}
	gnl_free_it(holder, 0);
	return (res);
}

int	do_holder(char *buff, char **holder, char **line)
{
	*holder = gnl_strjoin(holder, buff);
	if (gnl_strchr(*holder, '\n'))
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
		if (holder)
			return (gnl_free_it(&holder, -1));
	if (bytes && !holder)
		holder = gnl_calloc(1, 1);
	while (norm_killer(fd, buff, BUFFER_SIZE, &bytes) > 0)
		if (do_holder(buff, &holder, line))
			return (1);
	if (bytes < 0)
		return (gnl_free_it(&holder, bytes));
	if (gnl_strchr(holder, '\n'))
	{
		holder = get_line(&holder, line, '\n');
		return (1);
	}
	holder = get_line(&holder, line, '\n');
	return (gnl_free_it(&holder, 0));
}
