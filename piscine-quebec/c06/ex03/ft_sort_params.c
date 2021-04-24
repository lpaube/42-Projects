/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:31:24 by laube             #+#    #+#             */
/*   Updated: 2021/03/22 16:48:08 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	**ft_sort(int argc, char **argv);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	ft_sort(argc, argv);
	while (index < argc)
	{
		ft_putstr(argv[index]);
		index++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (s2[index] == '\0')
			return (1);
		if (s2[index] > s1[index])
			return (-1);
		if (s1[index] > s2[index])
			return (1);
		index++;
	}
	if (s2[index] != '\0')
		return (-1);
	return (0);
}

char	**ft_sort(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 1)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
				i = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	return (argv);
}
