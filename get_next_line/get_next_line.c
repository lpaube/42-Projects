/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/05/11 18:34:03 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 32

#include "get_next_line.h"

// TO DELETE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	get_next_line(int fd, char **line)
{
	char	*buff;
	int		i;

	i = 0;
	buff = malloc(BUFFER_SIZE * sizeof(char));
	while (i++ < 11)
	{
		read(fd, buff, 1);
	}
	printf("Output: \"%s\"", buff);


	return (0);
}

int	main(void)
{
	char	**line;
	int	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, line);
}
