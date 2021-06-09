/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/24 17:00:57 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	va_start(ap, fmt);
	ret = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_triage_struct(&ap, &(i), fmt, &ret);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			ret++;
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
