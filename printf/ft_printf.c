/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/21 15:28:32 by laube            ###   ########.fr       */
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

int		get_width(struct s_fmt *s_flag)
{
	char	*width_str;
	char	*start_width;
	int		counter;
	int		holder;
	int		width;

	holder = s_flag->curr_pos;
	counter = 0;
	while (ft_isdigit(s_flag->fmt[holder++]))
		counter++;
	width_str = ft_calloc(counter + 1, sizeof(char));
	start_width = width_str;
	while (ft_isdigit(s_flag->fmt[s_flag->curr_pos]))
	{
		*width_str = s_flag->fmt[s_flag->curr_pos++];
		width_str++;
	}
	width = ft_atoi((const char *)start_width);
	free(start_width);
	start_width = NULL;
	return (width);
}

int	ft_triage_flags(struct s_fmt *s_flag, va_list ap)
{
	while (s_flag->fmt[s_flag->curr_pos] != s_flag->type)
	{
		if (s_flag->fmt[s_flag->curr_pos] == '-')
			s_flag->left_justify = 1;
		if (s_flag->fmt[s_flag->curr_pos] == '0')
		{
			if (s_flag->left_justify == 0)
				s_flag->pad_zero = 1;
		}
		else if (ft_isdigit(s_flag->fmt[s_flag->curr_pos]))
			s_flag->width = get_width(s_flag);
		if (s_flag->fmt[s_flag->curr_pos] == s_flag->type)
			return (1);
			

		s_flag->curr_pos++;
	}
	return (0);
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
	flag.curr_pos = *i;
	flag.fmt = fmt;
	flag.type = 0;
	while (!str_holder && fmt[tmp])
	{
		str_holder = ft_strchr(FMT_TAB, fmt[tmp++]);
	}
	if (str_holder[0])
		flag.type = str_holder[0];
	if (ft_triage_flags(&flag, ap) == 1)
	{
		ft_triage(flag.type, ap, &flag.curr_pos, flag.fmt);
	}
	*i = flag.curr_pos;
}

void	ft_triage(char c, va_list ap, int *i, const char *fmt)
{
	if (c == 'c')
		c_val(ap);
	else if (c == 's')
		s_val(ap);
	else if (c == 'p')
		p_val(ap);
	else if (c == 'd' || c == 'i')
		d_val(ap);
	else if (c == 'u')
		u_val(ap);
	else if (c == 'x' || c == 'X')
		x_val(ap, c);
	else if (c == '%')
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
	ft_printf("Test: '%20s'\n", "Hello");
//	printf("Test: '%20s'\nTest: '%019s'\n", "Hello", "Hello");
	return (0);
}
