/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 17:54:49 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			ft_triage_struct(&ap, &i, fmt);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (0);
}
