/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/05/16 17:22:35 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*get_line(char *holder, char **line, char c)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
	while (holder[i] != c && holder[i])
		i++;
	*line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (holder[i] != c && holder[i])
	{
		(*line)[i] = holder[i];
		i++;
	}
	if (holder[i + 1])
	{
		res = ft_strdup(&holder[i + 1]);
		free_it(&holder);
	}
	return (res);
}

int	do_holder(char *buff, char **holder, int bytes, char **line)
{
	buff[bytes] = 0;
	if (buff)
		*holder = ft_strjoin(holder, buff);
	if (ft_strchr(*holder, '\n'))
	{
		free(buff);
		*holder = get_line(*holder, line, '\n');
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*holder;
	int			bytes;

	bytes = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (bytes && !holder)
		holder = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (-1);
	while ((bytes = read(fd, buff, BUFFER_SIZE)) > 0)
		if (do_holder(buff, &holder, bytes, line))
			return (1);
	if (bytes < 0)
		return (-1);
	free(buff);
	if (ft_strchr(holder, '\n'))
	{
		holder = get_line(holder, line, '\n');
		return (1);
	}
	get_line(holder, line, '\n');
	return (0);
}
