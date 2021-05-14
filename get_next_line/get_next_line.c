/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/05/14 18:01:19 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 32

#include "get_next_line.h"

// TO DELETE
#include <stdio.h>

void	ft_parse2(char *buff, char c, char **line)
{
	int		i;

	i = 0;
	//printf("line: '%s' | buff: '%s'\n", *line, buff);

	while (buff[i] != '\n')
	{
		(*line)[i] = buff[i];
		i++;
	}
	(*line)[i] = 0;
}

int	ft_strparse(char **buff, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(*buff, '\n')))
	{
		ft_parse2(*buff, '\n', line);
		*buff = tmp + 1;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*full_buff;
	int			bytes;

	buff[BUFFER_SIZE] = 0;
	if (full_buff == 0)
		full_buff = ft_calloc(BUFFER_SIZE + 1, 1);
	while ((bytes = read(fd, buff, BUFFER_SIZE) > 0))
	{
		if (bytes < 0)
			return (-1);
		full_buff = ft_strjoin(full_buff, buff);
		if (ft_strparse(&full_buff, line))
		{
			return (1);
		}
	}
	full_buff = ft_strjoin(full_buff, buff);
	if (ft_strparse(&full_buff, line))
	{
		if (bytes == 0)
		{
			full_buff = 0;
		}
		return (1);
	}
	return(-1);
}

int	main(void)
{
	char	**line;
	line = ft_calloc(5, sizeof(*line));
	*line = ft_calloc(10000, 1);
	int	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
	get_next_line(fd, line);
	printf("line: '%s'\n", *line);
}
