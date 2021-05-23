/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:17:29 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 17:55:38 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_uputnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	u_val_control(va_list *ap, struct s_fmt *flag)
{
	unsigned int	val;
	(void)flag;

	val = va_arg(*ap, int);
	ft_uputnbr_fd(val, 1);
}

void	u_val(va_list *ap, struct s_fmt *flag)
{
	unsigned int	val;
	(void)flag;

	val = va_arg(*ap, int);
	ft_uputnbr_fd(val, 1);
}
