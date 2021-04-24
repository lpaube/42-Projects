/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:32:23 by laube             #+#    #+#             */
/*   Updated: 2021/03/31 12:20:04 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	while (*str)
	{
		write(fd, &(*str), 1);
		str++;
	}
}

void	read_stdin(void)
{
	char	c;

	while (read(0, &c, 1))
	{
		ft_putchar(c);
	}
}

int	ft_cat(int argc, char **argv)
{
	int		i;
	int		fd;
	char	c;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr(2, basename(argv[0]));
			ft_putstr(2, ": ");
			ft_putstr(2, (argv[i]));
			ft_putstr(2, ": ");
			ft_putstr(2, strerror(errno));
			ft_putstr(2, "\n");
			return (0);
		}
		while (read(fd, &c, 1))
		{
			ft_putchar(c);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1 || (argv[1][0] == '-' && argv[1][1] == 0))
		read_stdin();
	else
	{
		ft_cat(argc, argv);
	}
}
