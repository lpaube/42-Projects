/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/20 15:00:28 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_uputnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_dtohex(int num, int *rm_zeros)
{
	int		remain;
	char	*range;

	range = "0123456789abcdef";
	remain = num % 16;
	if (num >= 16)
		ft_dtohex(num / 16, rm_zeros);
	if (*rm_zeros == 1 && remain == 0)
		return ;
	else
	{
		*rm_zeros = 0;
		ft_putchar_fd(range[remain], 1);
	}
}

void	ft_dtohex_neg(unsigned int num, int *rm_zeros)
{
	unsigned int		remain;
	char	*range;

	range = "0123456789abcdef";
	remain = num % 16;
	if (num >= 16)
		ft_dtohex(num / 16, rm_zeros);
	if (*rm_zeros == 1 && remain == 0)
		return ;
	else
	{
		*rm_zeros = 0;
		ft_putchar_fd(range[remain], 1);
	}
}

void	c_val(va_list ap)
{
	char	val;

	val = va_arg(ap, int);
	ft_putchar_fd(val, 1);
}

void	s_val(va_list ap)
{
	char	*val;

	val = va_arg(ap, char *);
	ft_putstr_fd(val, 1);
}

void	p_val(va_list ap)
{
	void			*val;
	int				i;
	unsigned char	*buf;
	int				rm_zeros;

	rm_zeros = 1;
	val = va_arg(ap, void *);
	i = sizeof(val) - 1;
	buf = ft_calloc(sizeof(val), sizeof(unsigned char));
	ft_memcpy(buf, &val, sizeof(val));
	ft_putstr_fd("0x", 1);
	while (buf[i] == 0 && i >= 0)
		if (i-- == 0)
		{
			ft_putchar_fd('0', 1);
			return ;
		}
	while (i >= 0)
	{
		if (buf[i] < 16 && rm_zeros == 0)
			ft_putchar_fd('0', 1);
		ft_dtohex(buf[i--], &rm_zeros);
		rm_zeros = 0;
	}
}

void	d_val(va_list ap)
{
	int	val;

	val = va_arg(ap, int);
	ft_putnbr_fd(val, 1);
}

void	u_val(va_list ap)
{
	unsigned int	val;

	val = va_arg(ap, int);
	ft_uputnbr_fd(val, 1);
}

void	x_val(va_list ap)
{
	int	val;
	int rm_zeros;
	int	neg;

	neg = 0;
	rm_zeros = 1;
	val = va_arg(ap, int);
	if (val < 0)
		ft_dtohex_neg((unsigned int)val, &rm_zeros);
	else
		ft_dtohex(val, &rm_zeros);
}

void	cap_x_val(va_list ap)
{
	int	val;
	int rm_zeros;
	int	neg;

	neg = 0;
	rm_zeros = 1;
	val = va_arg(ap, int);
	ft_dtohex(val, &rm_zeros);
}

void	ft_triage(char c, va_list ap)
{
	if (c == 'c')
		c_val(ap);
	if (c == 's')
		s_val(ap);
	if (c == 'p')
		p_val(ap);
	if (c == 'd' || c == 'i')
		d_val(ap);
	if (c == 'u')
		u_val(ap);
	if (c == 'x')
		x_val(ap);
	if (c == 'X')
		cap_x_val(ap);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			ft_triage(fmt[++i], ap);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*nice = "ok";
	printf("Pos hex: %x | Neg hex: %x\n", 159, -1010);
	ft_printf("Pos hex: %x | Neg hex: %x\n", 159, -1010);
	return (0);
}
