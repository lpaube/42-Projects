/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:12:23 by laube             #+#    #+#             */
/*   Updated: 2021/06/14 10:39:23 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

void	ft_putnstr_fd(char *s, int fd, int len)
{
	while (len > 0 && *s)
	{
		write(fd, s, 1);
		s++;
		len--;
	}
}

char	*is_percent(va_list *ap, struct s_fmt *flag)
{
	char	*val;

	if (flag->type != '%')
	{
		val = va_arg(*ap, char *);
		if (!val)
			val = "(null)";
		flag->fmt_len = ft_strlen(val);
		if (flag->fmt_len > flag->precision)
			if (flag->precision >= 0 && flag->prec_on == 1)
				flag->fmt_len = flag->precision;
	}
	else
	{
		val = "%";
		flag->fmt_len = 1;
	}
	return (val);
}

void	s_val_control(va_list *ap, struct s_fmt *flag)
{
	char	*val;

	val = is_percent(ap, flag);
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
	(*flag->ret) += flag->fmt_len;
}

int	main(void)
{
	ft_printf("MINE: %010s\n", "test");
	printf("REAL: %010s\n", "test");

	ft_printf("MINE: %010c\n", 't');
	printf("REAL: %010c\n", 't');
}
