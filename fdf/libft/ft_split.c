/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:25:59 by laube             #+#    #+#             */
/*   Updated: 2021/07/07 21:57:38 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		str_alloc(char **table, char const *s, char c);
static int		table_size(char const *s, char c);
static void		split_it(char **table, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**table;

	table = malloc((table_size(s, c) + 1) * sizeof(*table));
	if (!table)
		return (NULL);
	str_alloc(table, s, c);
	split_it(table, s, c);
	return (table);
}

static int	table_size(char const *s, char c)
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
			state = 1;
		}
		s++;
	}
	return (counter);
}

static void	str_alloc(char **table, char const *s, char c)
{
	int	state;
	int	counter;

	counter = 0;
	state = 0;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			state = 1;
		}
		if ((!*(s + 1) && state == 1) || (*s == c && state == 1))
		{
			*table = malloc((counter + 1) * (sizeof(**table)));
			table++;
			counter = 0;
			state = 0;
		}
		s++;
	}
}

static void	split_it(char **table, char const *s, char c)
{
	int	state;
	int	i;
	int	j;

	i = 0;
	j = 0;
	state = 0;
	while (*s)
	{
		if (*s != c)
		{
			table[i][j] = *s;
			j++;
			state = 1;
		}
		if ((!*(s + 1) || *s == c) && state == 1)
		{
			table[i][j] = '\0';
			i++;
			j = 0;
			state = 0;
		}
		s++;
	}
	table[i] = 0;
}
