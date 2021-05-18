/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/05/18 18:38:55 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	norm_killer(int fd, char **buff, int buff_size, int *bytes)
{
	*bytes = read(fd, *buff, buff_size);
	return (*bytes);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	i = 0;
	printf("STRDUP1\n");
	res = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	printf("STRDUP2\n");
	if (!res)
		return (NULL);
	printf("s1: '%s' | i: %d\n", s1, i);
	while (s1 && s1[i])
	{
		printf("Ss1: '%s' | i: %d\n", s1, i);
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	printf("STRDUP3\n");
	return (res);
}

char	*get_line(char **holder, char **line, char c, char **buff)
{
	int		i;
	char	*res;
	int		state;

	res = 0;
	i = 0;
	printf("GETLINE1\n");
	while ((*holder)[i] != c && (*holder)[i] && (*holder)[i] != 0)
		i++;
	printf("GETLINE2\n");
	*line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while ((*holder)[i] != c && (*holder)[i] && (*holder)[i] != 0)
	{
		(*line)[i] = (*holder)[i];
		i++;
		state = 1;
	}
	printf("GETLINE3\n");
	if ((*holder)[i + 1] != 0)
	{
		//printf("i: %d | holder[i + 1]: %c\n", i, (*holder)[i + 1]);
		res = ft_strdup(&((*holder)[i + 1]));
	}
	printf("GETLINE4\n");
	free_it(holder);
	free_it(buff);
	return (res);
}

int	do_holder(char **buff, char **holder, int bytes, char **line)
{
	(*buff)[bytes] = 0;
	printf("DOHOLDER1\n");
	if (*buff)
	{
		*holder = ft_strjoin(holder, buff);
	}
	printf("DOHOLDER2\n");
	if (ft_strchr(*holder, '\n'))
	{
		printf("DOHOLDER3\n");
		*holder = get_line(holder, line, '\n', buff);
		//printf("holderdo_holder: %s\n", *holder);
		free_it(buff);
		return (1);
	}
	printf("DOHOLDER4\n");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*holder = NULL;
	int			bytes;

	bytes = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
	{
		if (holder)
			free_it(&holder);
		return (-1);
	}
	printf("TEST1\n");
	if (bytes && !holder)
		holder = ft_calloc(1, 1);
	// holder allocated
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	printf("TEST2\n");
	// buff allocated
	if (!buff)
	{
		free_it(&holder);
		return (-1);
	}
	printf("TEST3\n");
	while (norm_killer(fd, &buff, BUFFER_SIZE, &bytes) > 0)
	{
		if (do_holder(&buff, &holder, bytes, line))
		{
			return (1);
		}
	}
	printf("TEST4\n");
	if (bytes < 0)
	{
		free_it(&holder);
		free_it(&buff);
		return (-1);
	}
	printf("TEST5\n");
	if (ft_strchr(holder, '\n'))
	{
		holder = get_line(&holder, line, '\n', &buff);
		return (1);
	}
	printf("TEST6\n");
	holder = get_line(&holder, line, '\n', &buff);
	free_it(&holder);
	return (0);
}
