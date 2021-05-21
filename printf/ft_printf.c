/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/20 23:21:55 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_uputnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_dtohex(int num, int *rm_zeros, char cap)
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
	unsigned int		remain;
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
		ft_dtohex(buf[i--], &rm_zeros, 0);
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

void	x_val(va_list ap, char c)
{
	int	val;
	int rm_zeros;
	int	cap;

	cap = 0;
	if (c == 'X')
		cap = 1;
	rm_zeros = 1;
	val = va_arg(ap, int);
	if (val < 0)
	{
		ft_dtohex_neg((unsigned int)val, &rm_zeros, cap);
	}
	else
	{
		ft_dtohex(val, &rm_zeros, cap);
	}
}

void	ft_triage_flags(struct s_fmt *s_flag)
{
	
}

void	ft_triage_struct(char c, va_list ap, int *i, const char *fmt)
{
	char			*str_holder;
	int				tmp;
	struct s_fmt	flag;

	tmp = *i;
	flag.width = 0;
	flag.precision = 0;
	flag.pad_zero = 0;
	flag.left_justify = 0;
	flag.start = *i;
	flag.curr_pos = i;
	flag.fmt = fmt;
	flag.type = 0;
	while (!str_holder && fmt[tmp])
	{
		str_holder = ft_strchr(FMT_TAB, fmt[tmp++]);
	}
	if (str_holder[0])
		flag.type = str_holder[0];
	printf("FLAG.TYPE: '%c'\n", flag.type);
	// HERE IS WHERE I LEFT OFF. WE NOW HAVE ALL THE REQUIRED INFO STORED IN STRUCT. JUST NEED TO PASS ap ALONG WITH STRUCT
	ft_triage_flags(&flag);

}

void	ft_triage(char c, va_list ap, int *i, const char *fmt)
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
	if (c == 'x' || c == 'X')
		x_val(ap, c);
	if (c == '%')
		ft_putchar_fd('%', 1);
	else
		ft_triage_struct(c, ap, i, fmt);
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
			ft_triage(fmt[++i], ap, &i, fmt);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	char	*nice = "ok";
	ft_printf("Test: '%20.4d'\nTest: '%19s'\n", "Hello", "Hello");
	printf("Test: '%20s'\nTest: '%19s'\n", "Hello", "Hello");
	return (0);
}
