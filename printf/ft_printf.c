/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/18 11:29:50 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	void	*val;
	int		i;
	unsigned char	buf[8];
	unsigned char	hi;
	unsigned char	lo;
	char			tmp[2];

	val = va_arg(ap, void *);
	i = sizeof(val) - 1;

	memcpy(buf, &val, sizeof(val));

	while (i >= 0)
	{
		printf("buf[i]: %d\n", buf[i]);
		hi = (buf[i] >> 4) & 0xf;
		lo = buf[i] & 0xf;
		tmp[0] = hi;
		tmp[1] = lo;

		tmp[0] += hi < 10 ? '0' : 'a' - 10;
		tmp[1] += lo < 10 ? '0' : 'a' - 10;

		write(1, tmp, 2);
		i--;
	}
	printf("	'val address: %p'\n", val);
}

void	d_val(va_list ap)
{
	int	val;

	val = va_arg(ap, int);
	ft_putnbr_fd(val, 1);
}

void	ft_triage(char c, va_list ap)
{
	if (c == 'c')
		c_val(ap);
	if (c == 's')
		s_val(ap);
	if (c == 'p')
		p_val(ap);
	if (c == 'd')
		d_val(ap);
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
	ft_printf("Hello there, this is the number: %d, ain't that a '%s', whoa there %p\n", 15, "CALL");
	return (0);
}
