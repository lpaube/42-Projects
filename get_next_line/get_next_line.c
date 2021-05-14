/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:17 by laube             #+#    #+#             */
/*   Updated: 2021/05/13 22:10:53 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 32

#include "get_next_line.h"

// TO DELETE
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE];
	char	*holder;

	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		holder += buff;

	}

	return (0);
}

int	main(void)
{
	char	**line;
	int	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, line);
}
