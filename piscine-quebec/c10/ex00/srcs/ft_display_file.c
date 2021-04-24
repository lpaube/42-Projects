/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:33:07 by laube             #+#    #+#             */
/*   Updated: 2021/03/29 17:36:10 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

int	main(int argc, char **argv)
{
	int		fd;
	char	c;

	if (argc < 2)
	{
		ft_putstr_fd(2, "File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(2, "Cannot read file.\n");
		return (0);
	}
	while (read(fd, &c, 1))
		ft_putchar(c);
	close(fd);
	return (0);
}
