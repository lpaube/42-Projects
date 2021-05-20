/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/19 22:53:32 by laube            ###   ########.fr       */
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

int	get_complement2(int c)
{
	if (c == 12)
		return (3);
	if (c == 13)
		return (2);
	if (c == 14)
		return (1);
	if (c == 15)
		return (0);
	return (0);
}

int	get_complement(int c)
{
	if (c == 0)
		return (15);
	if (c == 1)
		return (14);
	if (c == 2)
		return (13);
	if (c == 3)
		return (12);
	if (c == 4)
		return (11);
	if (c == 5)
		return (10);
	if (c == 6)
		return (9);
	if (c == 7)
		return (8);
	if (c == 8)
		return (7);
	if (c == 9)
		return (6);
	if (c == 10)
		return (5);
	if (c == 11)
		return (4);
	return (get_complement2(c));
}

void	ft_dtohex(int num, int *rm_zeros, int *neg)
{
	int		remain;
	char	*range;

	range = "0123456789abcdef";
	remain = num % 16;
	if (num >= 16)
		ft_dtohex(num / 16, rm_zeros, neg);
	if (*neg == 1)
		remain = get_complement(remain);
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
	int				neg;

	neg = 0;
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
		ft_dtohex(buf[i--], &rm_zeros, &neg);
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
	{
		val = (val + 1) * -1;
		neg = 1;
	}
	ft_dtohex(val, &rm_zeros, &neg);
}

void	cap_x_val(va_list ap)
{
	int	val;
	int rm_zeros;
	int	neg;

	neg = 0;
	rm_zeros = 1;
	val = va_arg(ap, int);
	ft_dtohex(val, &rm_zeros, &neg);
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
	printf("Pos hex: %x | Neg hex: %x\n", 1591, -1592);
	ft_printf("Pos hex: %x | Neg hex: %x\n", 1591, -1592);
	return (0);
}
