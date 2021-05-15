/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/05/15 19:27:54 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 32

#include "get_next_line.h"

// TO DELETE
#include <stdio.h>


char	*get_line(char *holder, char **line)
{
	int		i;

	i = 0;
	while (holder[i] != '\n' && holder[i])
		i++;
	*line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (holder[i] != '\n' && holder[i])
	{
		(*line)[i] = holder[i];
		i++;
	}
	if (holder[i + 1])
		return (&holder[i + 1]);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*holder;
	int			bytes;

	if (!holder)
		holder = ft_calloc(1, 1);
	if (!line)
		return (-1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (0);
	while ((bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		holder = ft_strjoin(holder, buff);
		if (ft_strchr(holder, '\n'))
		{
			free(buff);
			holder = get_line(holder, line);
			return (1);
		}
	}
	return (0);
}

int	main(void)
{
	char	*line;
	line = NULL;
	int	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("line: '%s'\n", line);
	get_next_line(fd, &line);
	printf("line: '%s'\n", line);
	get_next_line(fd, &line);
	printf("line: '%s'\n", line);
	get_next_line(fd, &line);
	printf("line: '%s'\n", line);
	get_next_line(fd, &line);
	printf("line: '%s'\n", line);
	get_next_line(fd, &line);
	printf("line: '%s'\n", line);
	get_next_line(fd, &line);
	printf("line: '%s'\n", line);
}
