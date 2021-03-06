/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:20:39 by laube             #+#    #+#             */
/*   Updated: 2021/05/24 17:00:25 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	c_val_control(va_list *ap, struct s_fmt *flag)
{
	char	val;

	val = va_arg(*ap, int);
	flag->fmt_len = 1;
	if (flag->left_justify)
	{
		ft_putchar_fd(val, 1);
		(*flag->ret)++;
		to_pad(flag);
	}
	else
	{
		to_pad(flag);
		ft_putchar_fd(val, 1);
		(*flag->ret)++;
	}
}
