/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:41:43 by laube             #+#    #+#             */
/*   Updated: 2021/03/29 12:35:45 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_struct
{
	int		counter;
	char	**table;
}	t_struct;

char			**ft_malloc_char(char **table, char *str, char *charset);
t_struct		ft_malloc_string(char *str, char *charset);
int				ft_ischarset(char str, char *charset);
char			**ft_split(char *str, char *charset);
char			*solve_it(char *dest, char *str, int counter);

char	**ft_split(char *str, char *charset)
{
	int			index;
	char		**table;
	int			arrlen;
	t_struct	value;

	index = 0;
	value = ft_malloc_string(str, charset);
	table = value.table;
	arrlen = value.counter;
	table = ft_malloc_char(table, str, charset);
	return (table);
}

t_struct	ft_malloc_string(char *str, char *charset)
{
	int			strState;
	t_struct	ret_val;

	strState = 1;
	ret_val.counter = 0;
	while (*str)
	{
		if (ft_ischarset(*str, charset))
			strState = 1;
		else
		{
			if (strState == 1)
				ret_val.counter++;
			strState = 0;
		}
		str++;
	}
	ret_val.table = malloc((ret_val.counter + 1) * sizeof(char *));
	return (ret_val);
}

int	ft_ischarset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	**ft_malloc_char(char **table, char *str, char *charset)
{
	int	counter;
	int	index;

	index = 0;
	counter = 0;
	while (*str)
	{
		while (ft_ischarset(*str, charset) == 0 && *str)
		{
			counter++;
			str++;
		}
		if (counter > 0)
		{
			table[index] = malloc((counter + 1) * sizeof(char));
			table[index] = solve_it(table[index], str - counter, counter);
			index++;
		}
		counter = 0;
		str++;
	}
	table[index] = 0;
	return (table);
}

char	*solve_it(char *dest, char *str, int counter)
{
	int	i;

	i = 0;
	while (counter > 0)
	{
		dest[i++] = *str;
		str++;
		counter--;
	}
	dest[i] = 0;
	return (dest);
}
