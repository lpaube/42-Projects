/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:52:18 by laube             #+#    #+#             */
/*   Updated: 2021/03/21 16:31:13 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);

// CREATE OUR TABLE
char **ft_create_table(int x)
{
	int	i;
	char **tab2;

	i = 0;
	x = x/4;

	tab2 = malloc(x * sizeof(char*));
	while (i < x)
	{
		tab2[i] = malloc(x * sizeof(char));
		i++;
	}
	return (tab2);
}

// TO ZERO THE OUTPUT TABLE
char	**ft_zero_output(char **table0, int len)
{
	int	i;
	int j;

	i = 0;
	while (i < len / 4)
	{
		j = 0;
		while (j < len / 4)
		{
			table0[i][j] = '0';
			j++;
		}
		i++;
	}
	return (table0);
}

// TO PRINT THE OUTPUT TABLE
void	ft_output(char **table, int len)
{
	int	i;
	int	j;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			ft_putchar(table[i][j]);
			if (j + 1 < len)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**ft_table_main(int len)
{
	char **table;

	table = ft_create_table(len);
	ft_zero_output(table, len);
	return (table);
}
