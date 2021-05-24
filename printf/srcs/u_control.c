/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:17:29 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 23:22:02 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	int_val_control(char *val_str, struct s_fmt *flag)
{
	int		tmp_len;

	flag->fmt_len = ft_strlen(val_str);
	tmp_len = flag->fmt_len;
	if (flag->precision < flag->fmt_len && flag->precision != -1)
		flag->pad_zero = ' ';
	if (flag->precision < flag->width && flag->precision != -1)
		flag->pad_zero = ' ';
	if (val_str[0] == '-')
		d_val_neg(flag, tmp_len, val_str);
	else
		d_val_pos(flag, tmp_len, val_str);
}

void	u_val_control(va_list *ap, struct s_fmt *flag)
{
	unsigned int	val;
	int				free_state;
	char			*val_str;

	val_str = "";
	free_state = 0;
	val = va_arg(*ap, unsigned int);
	if (!(val == 0 && flag->precision == 0))
	{
		free_state = 1;
		val_str = ft_utoa(val);
	}
	int_val_control(val_str, flag);

	free_it((void **)&val_str, free_state);
}
