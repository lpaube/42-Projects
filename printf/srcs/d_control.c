/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:04:01 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 23:21:02 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	d_val_pos(struct s_fmt *flag, int tmp_len, char *val_str)
{
	if (flag->left_justify)
	{
		print_precision(flag);
		ft_putstr_fd(val_str, 1);
		to_pad(flag);
	}
	else
	{
		while (flag->precision > flag->fmt_len)
			flag->fmt_len++;
		to_pad(flag);
		flag->fmt_len = tmp_len;
		print_precision(flag);
		ft_putstr_fd(val_str, 1);
	}
}

void	d_val_neg(struct s_fmt *flag, int tmp_len, char *val_str)
{
	if (flag->left_justify)
	{
		ft_putchar_fd('-', 1);
		flag->fmt_len--;
		print_precision(flag);
		flag->fmt_len++;
		ft_putstr_fd(&(val_str[1]), 1);
		to_pad(flag);
	}
	else
	{
		if (flag->pad_zero == '0')
			ft_putchar_fd('-', 1);
		if (flag->precision >= flag->fmt_len)
			flag->fmt_len = flag->precision + 1;
		to_pad(flag);
		flag->fmt_len = tmp_len - 1;
		if (flag->pad_zero == ' ')
			ft_putchar_fd('-', 1);
		print_precision(flag);
		ft_putstr_fd(&(val_str[1]), 1);
	}
}


void	d_val_control(va_list *ap, struct s_fmt *flag)
{
	int		val;
	int		tmp_len;
	char	*val_str;
	int		free_state;

	val_str = "";
	val = va_arg(*ap, int);
	free_state = 0;
	if (!(val == 0 && flag->precision == 0))
	{
		free_state = 1;
		val_str = ft_itoa(val);
	}
	flag->fmt_len = ft_strlen(val_str);
	tmp_len = flag->fmt_len;
	if (flag->precision < flag->fmt_len && flag->precision != -1)
		flag->pad_zero = ' ';
	if (flag->precision < flag->width && flag->precision != -1)
		flag->pad_zero = ' ';
	if (val < 0)
		d_val_neg(flag, tmp_len, val_str);
	else
		d_val_pos(flag, tmp_len, val_str);
	free_it((void *)&val_str, free_state);
}
