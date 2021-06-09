/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:03:40 by laube             #+#    #+#             */
/*   Updated: 2021/05/24 20:42:18 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	x_val_len(unsigned int val)
{
	int	remain;
	int	zeros;
	int	len;

	len = 0;
	remain = 0;
	zeros = 0;
	while (val > 0)
	{
		if (val % 16 == 0)
			zeros++;
		else
		{
			len++;
			len += zeros;
			zeros = 0;
		}
		val = val / 16;
	}
	return (len);
}

void	x_val_left(unsigned int val, struct s_fmt *flag, int cap, int rm_zeros)
{
	print_precision(flag);
	if (val == 0 && (flag->prec_on == 0 || flag->precision < 0))
	{
		ft_putchar_fd('0', 1);
		(*flag->ret)++;
	}
	else
		ft_dtohex(val, &rm_zeros, cap, flag);
	to_pad(flag);
}

void	x_val_justify(unsigned int val, struct s_fmt *flag, int cap, int i)
{
	int	rm_zeros;

	rm_zeros = 1;
	if (flag->left_justify)
		x_val_left(val, flag, cap, rm_zeros);
	else
	{
		while (flag->precision > flag->fmt_len)
			flag->fmt_len++;
		to_pad(flag);
		flag->fmt_len = i;
		print_precision(flag);
		if (val == 0 && (flag->prec_on == 0 || flag->precision < 0))
		{
			ft_putchar_fd('0', 1);
			(*flag->ret)++;
		}
		else
			ft_dtohex(val, &rm_zeros, cap, flag);
	}
}

void	x_val_control(va_list *ap, struct s_fmt *flag)
{
	int	val;
	int	cap;
	int	tmp_len;

	cap = 0;
	val = (unsigned int)(va_arg(*ap, int));
	if (flag->type == 'X')
		cap = 1;
	flag->fmt_len = x_val_len(val);
	if (val == 0 && flag->prec_on == 0)
		flag->fmt_len++;
	tmp_len = flag->fmt_len;
	if (tmp_len >= flag->precision && flag->prec_on == 1)
		flag->pad_zero = ' ';
	if (flag->width >= flag->precision && flag->prec_on == 1)
		flag->pad_zero = ' ';
	x_val_justify(val, flag, cap, tmp_len);
}

void	x_val(char c, struct s_fmt *flag, unsigned int val)
{
	int	rm_zeros;
	int	cap;

	(void)flag;
	cap = 0;
	if (c == 'X')
		cap = 1;
	rm_zeros = 1;
	if (val < 0)
		ft_dtohex(val, &rm_zeros, cap, flag);
	else
		ft_dtohex(val, &rm_zeros, cap, flag);
}
