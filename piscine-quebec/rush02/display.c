/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:47:39 by laube             #+#    #+#             */
/*   Updated: 2021/03/27 15:11:13 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

// TOOLS
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// END OF TOOLS

int		ft_display_zero(int n, struct s_dict *dict)
{
	int		i;
	char	*tab;

	if (!(tab = malloc(sizeof(*tab) * (((n * 3) + 1) + 1))))
		return (0);
	tab[0] = '1';
	i = 0;
	while (++i < (n * 3) + 1)
		tab[i] = '0';
	tab[i] = '\0';
	i = 0;
	while (dict[i].value != 0)
	{
		if (ft_strcmp(tab, dict[i].value) == 0)
		{
			ft_putstr(" ");
			ft_putstr(dict[i].wrt);
			return (1);
		}
		i++;
	}
	free(tab);
	return (0);
}

void	ft_display_hundred_units(char *str, struct s_dict *dict, int *f)
{
	int i;

	i = 0;
	while (dict[i].value != 0 && str != 0)
	{
		if (ft_strcmp(str, dict[i].value) == 0)
		{
			if (*f != 0)
				ft_putstr(" ");
			*f = 1;
			ft_putstr(dict[i].wrt);
			return ;
		}
		i++;
	}
}

void	ft_display_hundred(char *str, struct s_dict *dict, int *f)
{
	int i;

	i = 0;
	while (dict[i].value != 0 && str != 0)
	{
		if (ft_strcmp(str, dict[i].value) == 0)
		{
			if (*f != 0)
				ft_putstr(" ");
			*f = 1;
			ft_putstr(dict[i].wrt);
			return ;
		}
		i++;
	}
}

void	ft_display_dozen(char *str, struct s_dict *dict, int *f)
{
	int i;

	i = 0;
	while (dict[i].value != 0 && str != 0)
	{
		if (ft_strcmp(str, dict[i].value) == 0)
		{
			if (*f != 0)
				ft_putstr(" ");
			*f = 1;
			ft_putstr(dict[i].wrt);
			return ;
		}
		i++;
	}
}

void	ft_display_unit(char *str, struct s_dict *dict, int *f)
{
	int i;

	i = 0;
	while (dict[i].value != 0 && str != 0)
	{
		if (ft_strcmp(str, dict[i].value) == 0)
		{
			if (*f != 0)
				ft_putstr(" ");
			*f = 1;
			ft_putstr(dict[i].wrt);
			return ;
		}
		i++;
	}
}
