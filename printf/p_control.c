/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:09:53 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 16:37:30 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_val_len(unsigned char *buff, int init_len)
{
	int	res_len;

	res_len = 2;
	while (init_len >= 0 && buff[init_len] == 0)
		init_len--;
	if (buff[init_len] < 16)
	{
		res_len++;
		init_len--;
	}
	while (init_len >= 0)
	{
		res_len += 2;
		init_len--;
	}
	if (res_len == 2)
		return (3);
	return (res_len);
}

void	p_val(unsigned char *buff, int i)
{
	int				rm_zeros;

	rm_zeros = 1;
	ft_putstr_fd("0x", 1);
	while (buff[i] == 0 && i >= 0)
		if (i-- == 0)
		{
			ft_putchar_fd('0', 1);
			return ;
		}
	while (i >= 0)
	{
		if (buff[i] < 16 && rm_zeros == 0)
			ft_putchar_fd('0', 1);
		ft_dtohex(buff[i--], &rm_zeros, 0);
		rm_zeros = 0;
	}
}

void	p_val_control(va_list *ap, struct s_fmt *flag)
{
	void	*val;
	unsigned char	*buff;

	val = va_arg(*ap, void *);
	buff = ft_calloc(sizeof(val), sizeof(unsigned char));
	ft_memcpy(buff, &val, sizeof(val));
	flag->fmt_len = p_val_len(buff, sizeof(val) - 1);
	if (flag->left_justify)
	{
		p_val(buff, sizeof(val) - 1);
		to_pad(flag);
	}
	else
	{
		to_pad(flag);
		p_val(buff, sizeof(val) - 1);
	}
}
