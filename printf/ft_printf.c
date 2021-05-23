/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:51 by laube             #+#    #+#             */
/*   Updated: 2021/05/22 23:32:54 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_uputnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_dtohex(unsigned int num, int *rm_zeros, char cap)
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
	if (flag->fmt_len > flag->precision && flag->precision >= 0)
		flag->fmt_len = flag->precision;
	if (flag->left_justify)
	{
		ft_putnstr_fd(val, 1, flag->fmt_len);
		to_pad(flag);
	}
	else
	{
		to_pad(flag);
		ft_putnstr_fd(val, 1, flag->fmt_len);
	}
}

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

void	print_precision(struct s_fmt *flag)
{
	if (flag->precision < flag->fmt_len && flag->precision != -1)
		flag->pad_zero = ' ';
	while (flag->precision > flag->fmt_len)
	{
		ft_putchar_fd('0', 1);
		flag->fmt_len++;
	}
}

void	d_val_pos(struct s_fmt *flag, int tmp_len, char *val_str)
{
	if (flag->left_justify)
	{
		print_precision(flag);
		ft_putstr_fd(val_str, 1);
		to_pad(flag);
	}
	else
	{
		while (flag->precision > flag->fmt_len)
			flag->fmt_len++;
		to_pad(flag);
		flag->fmt_len = tmp_len;
		print_precision(flag);
		ft_putstr_fd(val_str, 1);
	}
}

void	d_val_neg(struct s_fmt *flag, int tmp_len, char *val_str)
{
	if (flag->left_justify)
	{
		ft_putchar_fd('-', 1);
		flag->fmt_len--;
		print_precision(flag);
		flag->fmt_len++;
		ft_putstr_fd(&(val_str[1]), 1);
		to_pad(flag);
	}
	else
	{
		if (flag->pad_zero == '0')
			ft_putchar_fd('-', 1);
		if (flag->precision >= flag->fmt_len)
			flag->fmt_len = flag->precision + 1;
		to_pad(flag);
		flag->fmt_len = tmp_len - 1;
		if (flag->pad_zero == ' ')
			ft_putchar_fd('-', 1);
		print_precision(flag);
		ft_putstr_fd(&(val_str[1]), 1);
	}
}

void	d_val_control(va_list *ap, struct s_fmt *flag)
{
	int	val;
	int	tmp_len;
	char	*val_str;

	val = va_arg(*ap, int);
	val_str = ft_itoa(val);
	flag->fmt_len = ft_strlen(val_str);
	tmp_len = flag->fmt_len;
	if (flag->precision < flag->fmt_len && flag->precision != -1)
		flag->pad_zero = ' ';
	if (flag->precision < flag->width && flag->precision != -1)
		flag->pad_zero = ' ';

	if (val < 0)
		d_val_neg(flag, tmp_len, val_str);
	else
		d_val_pos(flag, tmp_len, val_str);
	free(val_str);
	val_str = NULL;
}

void	u_val_control(va_list *ap, struct s_fmt *flag)
{
	unsigned int	val;

	val = va_arg(*ap, int);
	ft_uputnbr_fd(val, 1);
}

void	u_val(va_list *ap, struct s_fmt *flag)
{
	unsigned int	val;

	val = va_arg(*ap, int);
	ft_uputnbr_fd(val, 1);
}

int	x_val_len(unsigned int val)
{
	int	remain;
	int	zeros;
	int	len;

	len = 0;
	remain = 0;
	while (val > 0)
	{
		if (val % 16 == 0)
			zeros++;
		else
		{
			len++;
			len += zeros;
			zeros = 0;
		}
		val = val / 16;
	}
	return (len);
}

void	x_val_control(va_list *ap, struct s_fmt *flag)
{
	int	val;
	int	rm_zeros;
	int	cap;
	int	tmp_len;

	cap = 0;
	rm_zeros = 1;
	val = (unsigned int)(va_arg(*ap, int));
	if (flag->type == 'X')
		cap = 1;
	flag->fmt_len = x_val_len(val);
	tmp_len = flag->fmt_len;
	if (tmp_len >= flag->precision && flag->precision != -1)
		flag->pad_zero = ' ';
	if (flag->left_justify)
	{
		print_precision(flag);
		ft_dtohex(val, &rm_zeros, cap);
		to_pad(flag);
	}
	else
	{
		while (flag->precision > flag->fmt_len)
			flag->fmt_len++;
		to_pad(flag);
		flag->fmt_len = tmp_len;
		print_precision(flag);
		ft_dtohex(val, &rm_zeros, cap);
	}
}

void	x_val(char c, struct s_fmt *flag, unsigned int val)
{
	int rm_zeros;
	int	cap;

	cap = 0;
	if (c == 'X')
		cap = 1;
	rm_zeros = 1;
	if (val < 0)
	{
		ft_dtohex_neg(val, &rm_zeros, cap);
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

	precision = 0;
	i = 0;
	s_flag->curr_pos++;
	if (s_flag->fmt[s_flag->curr_pos] == '*')
		return (va_arg(*ap, int));
	counter = mod_strlen(&(s_flag->fmt[s_flag->curr_pos]));
	if (!counter)
		return (0);
	pr = ft_calloc(mod_strlen(&(s_flag->fmt[s_flag->curr_pos])), sizeof(char));
	while (i < counter)
	{
		pr[i] = s_flag->fmt[s_flag->curr_pos];
		i++;
		pr[i] = 0;
		s_flag->curr_pos++;
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
		p_val_control(ap, flag);
	else if (c == 'd' || c == 'i' || c == 'u')
		d_val_control(ap, flag);
	/*	
	else if (c == 'u')
		u_val_control(ap, flag);
	*/
	else if (c == 'x' || c == 'X')
		x_val_control(ap, flag);
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
	char	*not_nice = 0;
	// Character (c)
	printf("Char(c):\n");
	printf("real(c): Test1: '%c' | Test2: '%4c' | Test3: '%5c' | Test4: '%-5c' | Test5: '%-*c'\n", 'H', 'H', 'H', 'H', 2, 'A');
	ft_printf("ft(c)  : Test1: '%c' | Test2: '%4c' | Test3: '%5c' | Test4: '%-5c' | Test5: '%-*c'\n", 'H', 'H', 'H', 'H', 2, 'A');
	// String (s)
	printf("\nString(s):\n");
	printf("real(s): Test1: '%s' | Test2: '%.4s' | Test3: '%6.4s' | Test4: '%-6.4s' | Test5: '%4.6s' | Test6: '%*.*s'\n", "Hello", "Hello", "Hello", "Hello", "Hello", 6, 3, "Hello");
	ft_printf("ft(s)  : Test1: '%s' | Test2: '%.4s' | Test3: '%6.4s' | Test4: '%-6.4s' | Test5: '%4.6s' | Test6: '%*.*s'\n", "Hello", "Hello", "Hello", "Hello", "Hello", 6, 3, "Hello");
	// Pointer (p)
	printf("\nPointer(p):\n");
	printf("real(p): Test1: '%p' | Test2: '%14p' | Test3: '%-14p' | Test4: '%*p'\n", nice, not_nice, nice, 14, nice);
	ft_printf("ft(p)  : Test1: '%p' | Test2: '%14p' | Test3: '%-14p' | Test4: '%*p'\n", nice, not_nice, nice, 14, nice);
	// Integer (d)
	printf("\nInteger(d):\n");
	printf("real(d): Test1: '%10.d' | Test2: '%015.4d' | Test3: '%-10.7d' | Test4: '%-*.*d' | Test5: '%010.8d' | Test 6: '%2.d'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	ft_printf("ft(d)  : Test1: '%10.d' | Test2: '%015.4d' | Test3: '%-10.7d' | Test4: '%-*.*d' | Test5: '%010.8d' | Test 6: '%2.d'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	// Integer (i)
	printf("\nInteger(i):\n");
	printf("real(i): Test1: '%10.i' | Test2: '%015.4i' | Test3: '%-10.7i' | Test4: '%-*.*i' | Test5: '%010.8i' | Test 6: '%2.i'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	ft_printf("ft(i)  : Test1: '%10.i' | Test2: '%015.4i' | Test3: '%-10.7i' | Test4: '%-*.*i' | Test5: '%010.8i' | Test 6: '%2.i'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	// Unsigned Integer (u)
	printf("\nUnsigned Integer(u):\n");
	printf("real(i): Test1: '%10.u' | Test2: '%015.4u' | Test3: '%-10.7u' | Test4: '%-*.*u' | Test5: '%010.8u' | Test 6: '%2.u'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	ft_printf("ft(i)  : Test1: '%10.u' | Test2: '%015.4u' | Test3: '%-10.7u' | Test4: '%-*.*u' | Test5: '%010.8u' | Test 6: '%2.u'\n", -142, -142, INT_MIN, 10, 3, 12345, 12345, 4);
	// Hexadecimal (x)
	printf("\nHexadecimal (x & X):\n");
	printf("real(x): Test1: '%12x' | Test2: '%-12X' | Test3: '%12.5x' | Test4: '%012.5X'%% |%%%% Test5: '%012x'\n", 79527482, 79527482, 79527482, 79527482, -79527482);
	ft_printf("ft(x)  : Test1: '%12x' | Test2: '%-12X' | Test3: '%12.5x' | Test4: '%012.5X'%% |%%%% Test5: '%012x'\n", 79527482, 79527482, 79527482, 79527482, -79527482);
}
