/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:12:23 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 16:40:16 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr_fd(char *s, int fd, int len)
{
	while (len > 0 && *s)
	{
		write(fd, s, 1);
		s++;
		len--;
	}
}

void	s_val_control(va_list *ap, struct s_fmt *flag)
{
	char	*val;

	val = va_arg(*ap, char *);
	flag->fmt_len = ft_strlen(val);
	if (flag->fmt_len > flag->precision && flag->precision >= 0)
		flag->fmt_len = flag->precision;
	if (flag->left_justify)
	{
		ft_putnstr_fd(val, 1, flag->fmt_len);
		to_pad(flag);
	}
	else
	{
		to_pad(flag);
		ft_putnstr_fd(val, 1, flag->fmt_len);
	}
}
