/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:03:40 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 16:34:58 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dtohex(unsigned int num, int *rm_zeros, char cap)
{
	int		remain;
	char	*range;

	range = "0123456789abcdef";
	remain = num % 16;
	if (num >= 16)
		ft_dtohex(num / 16, rm_zeros, cap);
	if (*rm_zeros == 1 && remain == 0)
		return ;
	else
	{
		*rm_zeros = 0;
		if (cap)
			ft_putchar_fd(ft_toupper(range[remain]), 1);
		else
			ft_putchar_fd(range[remain], 1);
	}
}

void	ft_dtohex_neg(unsigned int num, int *rm_zeros, char cap)
{
	unsigned int	remain;
	char			*range;

	range = "0123456789abcdef";
	remain = num % 16;
	if (num >= 16)
		ft_dtohex(num / 16, rm_zeros, cap);
	if (*rm_zeros == 1 && remain == 0)
		return ;
	else
	{
		*rm_zeros = 0;
		if (cap)
			ft_putchar_fd(ft_toupper(range[remain]), 1);
		else
			ft_putchar_fd(range[remain], 1);
	}
}

int	x_val_len(unsigned int val)
{
	int	remain;
	int	zeros;
	int	len;

	len = 0;
	remain = 0;
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

void	x_val_control(va_list *ap, struct s_fmt *flag)
{
	int	val;
	int	rm_zeros;
	int	cap;
	int	tmp_len;

	cap = 0;
	rm_zeros = 1;
	val = (unsigned int)(va_arg(*ap, int));
	if (flag->type == 'X')
		cap = 1;
	flag->fmt_len = x_val_len(val);
	tmp_len = flag->fmt_len;
	if (tmp_len >= flag->precision && flag->precision != -1)
		flag->pad_zero = ' ';
	if (flag->left_justify)
	{
		print_precision(flag);
		ft_dtohex(val, &rm_zeros, cap);
		to_pad(flag);
	}
	else
	{
		while (flag->precision > flag->fmt_len)
			flag->fmt_len++;
		to_pad(flag);
		flag->fmt_len = tmp_len;
		print_precision(flag);
		ft_dtohex(val, &rm_zeros, cap);
	}
}

void	x_val(char c, struct s_fmt *flag, unsigned int val)
{
	int rm_zeros;
	int	cap;

	cap = 0;
	if (c == 'X')
		cap = 1;
	rm_zeros = 1;
	if (val < 0)
	{
		ft_dtohex_neg(val, &rm_zeros, cap);
	}
	else
	{
		ft_dtohex(val, &rm_zeros, cap);
	}
}
