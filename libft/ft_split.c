/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:25:59 by laube             #+#    #+#             */
/*   Updated: 2021/04/27 23:27:36 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_alloc(char **table, char const *s, char c);
int		table_size(char const *s, char c);
void	split_it(char **table, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		state;

	state = 1;
	table = malloc((table_size(s, c) * (sizeof(*table))) + 1);
	if (!table)
		return (NULL);
	str_alloc(table, s, c);
	split_it(table, s, c);
	return (table);
}

int	table_size(char const *s, char c)
{
	int	counter;
	int	state;

	counter = 0;
	state = 1;
	while (*s)
	{
		if (*s != c && state == 1)
		{
			counter++;
			state = 0;
		}
		else if (*s == c && state == 0)
		{
			state = 1
		}
		s++;
	}
	return (counter);
}

void str_alloc(char **table, char const *s, char c)
{
	int	state;
	int counter;

	counter = 0;
	state = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			state = 1;
		}
		else if (*s == c && state == 1)
		{
			*table = malloc((counter * sizeof(char)) + 1);
			table++;
			counter = 0;
			state = 0;
		}
		s++;
	}
}

void	split_it(char **table, char const *s, char c)
{
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			**table = *s;
			(*table)++;
			state = 1;
		}
		else if (*s == c && state == 1)
		{
			**table = '\0';
			table++;
			state = 0;
		}
		s++;
	}
	*table = 0;
}

int	main(void)
{
	char **table = ft_split("what is up with all this mess", ' ');
	while (table)
	{
		printf("%s", *table);
		table++;
	}
}
