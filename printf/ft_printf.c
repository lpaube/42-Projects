/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/22 00:45:03 by laube            ###   ########.fr       */
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

void	to_pad(struct s_fmt *flag)
{
	int	tmp;

	tmp = 0;
	while (flag->width > flag->fmt_len + tmp)
	{
		ft_putchar_fd(flag->pad_zero, 1);
		tmp++;
	}
}

void	c_val_control(va_list *ap, struct s_fmt *flag)
{
	char	val;

	val = va_arg(*ap, int);
	flag->fmt_len = 1;
	if (flag->left_justify)
	{
		ft_putchar_fd(val, 1);
		to_pad(flag);
	}
	else
	{
		to_pad(flag);
		ft_putchar_fd(val, 1);
	}
}

void	ft_putnstr_fd(char *s, int fd, int len)
{
	while (len > 0 && *s)
	{
		write(fd, s, 1);
		s++;
		len--;
	}
}

void	s_val_control(va_list *ap, struct s_fmt *flag)
{
	char	*val;

	val = va_arg(*ap, char *);
	flag->fmt_len = ft_strlen(val);
	//printf("fmtlen: '%d' | precision: '%d'\n", flag->fmt_len, flag->precision);
	if (flag->fmt_len > flag->precision && flag->precision >= 0)
		flag->fmt_len = flag->precision;
	if (flag->left_justify)
	{
		//printf("1fmtlen: '%d' | precision: '%d'\n", flag->fmt_len, flag->precision);
		ft_putnstr_fd(val, 1, flag->fmt_len);
		to_pad(flag);
	}
	else
	{
		//printf("2fmtlen: '%d' | precision: '%d'\n", flag->fmt_len, flag->precision);
		to_pad(flag);
		ft_putnstr_fd(val, 1, flag->fmt_len);
	}
	
}

void	p_val(va_list *ap, struct s_fmt *flag)
{
	void			*val;
	int				i;
	unsigned char	*buf;
	int				rm_zeros;

	rm_zeros = 1;
	val = va_arg(*ap, void *);
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

void	d_val(va_list *ap, struct s_fmt *flag)
{
	int	val;

	val = va_arg(*ap, int);
	ft_putnbr_fd(val, 1);
}

void	u_val(va_list *ap, struct s_fmt *flag)
{
	unsigned int	val;

	val = va_arg(*ap, int);
	ft_uputnbr_fd(val, 1);
}

void	x_val(va_list *ap, char c, struct s_fmt *flag)
{
	int	val;
	int rm_zeros;
	int	cap;

	cap = 0;
	if (c == 'X')
		cap = 1;
	rm_zeros = 1;
	val = va_arg(*ap, int);
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

int	mod_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (ft_isdigit(str[counter]))
		counter++;
	return (counter);
}

int	get_precision(struct s_fmt *s_flag, va_list *ap)
{
	int		counter;
	char	*pr;
	int		precision;
	int		i;

	i = 0;
	s_flag->curr_pos++;
	if (s_flag->fmt[s_flag->curr_pos] == '*')
		return (va_arg(*ap, int));
	counter = mod_strlen(&(s_flag->fmt[s_flag->curr_pos]));
	pr = ft_calloc(mod_strlen(&(s_flag->fmt[s_flag->curr_pos])), sizeof(char));
	while (i < counter)
	{
		pr[i] = s_flag->fmt[s_flag->curr_pos++];
		i++;
	}
	precision = ft_atoi(pr);
	free(pr);
	return (precision);
}

int	ft_triage_flags(struct s_fmt *s_flag, va_list *ap)
{
	while (s_flag->fmt[s_flag->curr_pos])
	{
		if (s_flag->fmt[s_flag->curr_pos] == '-')
		{
			s_flag->left_justify = 1;
		}
		if (ft_isdigit(s_flag->fmt[s_flag->curr_pos]))
		{
			if (s_flag->fmt[s_flag->curr_pos] == '0')
			{
				if (s_flag->left_justify == 0)
					s_flag->pad_zero = '0';
				s_flag->curr_pos++;
			}
			if (ft_isdigit(s_flag->fmt[s_flag->curr_pos]))
			{
				s_flag->width = get_width(s_flag);
			}
		}
		if (s_flag->fmt[s_flag->curr_pos] == '*')
			s_flag->width = va_arg(*ap, int);
		if (s_flag->fmt[s_flag->curr_pos] == '.')
		{
			s_flag->precision = get_precision(s_flag, ap);
		}

		if (s_flag->fmt[s_flag->curr_pos] == s_flag->type)
		{
			return (1);
		}
		s_flag->curr_pos++;
	}
	return (0);
}

void	ft_triage_struct(char c, va_list *ap, int *i, const char *fmt)
{
	char			*str_holder;
	int				tmp;
	struct s_fmt	flag;

	str_holder = 0;
	tmp = *i;
	flag.width = 0;
	flag.precision = -1;
	flag.pad_zero = ' ';
	flag.left_justify = 0;
	flag.start = *i;
	flag.curr_pos = *i;
	flag.fmt = fmt;
	flag.type = 0;
	while (fmt[tmp] && !str_holder)
	{
		str_holder = ft_strchr(FMT_TAB, fmt[tmp++]);
	}
	if (str_holder[0])
		flag.type = str_holder[0];
	if (ft_triage_flags(&flag, ap) == 1)
	{
		ft_triage(flag.type, ap, &flag);
	}
	*i = flag.curr_pos;
}

void	ft_triage(char c, va_list *ap, struct s_fmt *flag)
{
	if (c == 'c')
		c_val_control(ap, flag);
	else if (c == 's')
		s_val_control(ap, flag);
	else if (c == 'p')
		p_val(ap, flag);
	else if (c == 'd' || c == 'i')
		d_val(ap, flag);
	else if (c == 'u')
		u_val(ap, flag);
	else if (c == 'x' || c == 'X')
		x_val(ap, c, flag);
	else if (c == '%')
		ft_putchar_fd('%', 1);
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
			ft_triage_struct(fmt[++i], &ap, &i, fmt);
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
	printf("real(c): Test1: '%c' | Test2: '%4c' | Test3: '%5c' | Test4: '%-5c' | Test5: '%-*c'\n", 'H', 'H', 'H', 'H', 2, 'A');
	ft_printf("ft(c)  : Test1: '%c' | Test2: '%4c' | Test3: '%5c' | Test4: '%-5c' | Test5: '%-*c'\n", 'H', 'H', 'H', 'H', 2, 'A');
	printf("real(s): Test1: '%s' | Test2: '%.4s' | Test3: '%6.4s' | Test4: '%-6.4s' | Test5: '%4.6s' | Test6: '%*.*s'\n", "Hello", "Hello", "Hello", "Hello", "Hello", 6, 3, "Hello");
	ft_printf("ft(s)  : Test1: '%s' | Test2: '%.4s' | Test3: '%6.4s' | Test4: '%-6.4s' | Test5: '%4.6s' | Test6: '%*.*s'\n", "Hello", "Hello", "Hello", "Hello", "Hello", 6, 3, "Hello");
	return (0);
}
