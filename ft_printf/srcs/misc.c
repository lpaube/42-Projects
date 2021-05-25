/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:22:24 by laube             #+#    #+#             */
/*   Updated: 2021/05/24 22:57:17 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_dtohex(unsigned int num, int *rm_zeros, char cap, struct s_fmt *fg)
{
	int			remain;
	char		*range;

	range = "0123456789abcdef";
	remain = num % 16;
	if (num >= 16)
		ft_dtohex(num / 16, rm_zeros, cap, fg);
	if (*rm_zeros == 1 && remain == 0)
		return ;
	else
	{
		*rm_zeros = 0;
		if (cap)
			ft_putchar_fd(ft_toupper(range[remain]), 1);
		else
			ft_putchar_fd(range[remain], 1);
		(*fg->ret)++;
	}
}

int	mod_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (ft_isdigit(str[counter]))
		counter++;
	return (counter);
}

int	free_it(void **mem, int free_state)
{
	if (free_state == 1)
	{
		free(*mem);
		*mem = NULL;
		return (1);
	}
	return (0);
}
