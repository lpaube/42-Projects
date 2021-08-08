#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>

typedef struct s_flags
{
	char	type;
	int		width;
	int		precision;
	int		precision_active;
}	t_flags;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(const char **fmt)
{
	 int	num;

	 num = 0;
	 while (**fmt >= '0' && **fmt <= '9')
	 {
		num = (num * 10) + (**fmt - '0');
		(*fmt)++;
	 }
	 return (num);
}

t_flags	set_flags(const char **fmt)
{
	t_flags	flag;

	(*fmt)++;
	flag.width = ft_atoi(fmt);
	if (**fmt == '.')
	{
		flag.precision_active = 1;
		(*fmt)++;
		flag.precision = ft_atoi(fmt);
	}
	else
	{
		flag.precision_active = 0;
		flag.precision = 0;
	}
	flag.type = **fmt;
	(*fmt)++;
	return (flag);
}

void	convert_s(t_flags flag, char *str, int *counter)
{
	int	printed_chars;
	int	padding;

	padding = 0;
	printed_chars = ft_strlen(str);
	if (flag.precision < printed_chars && flag.precision_active)
		printed_chars = flag.precision;
	if (flag.width > printed_chars)
		padding = flag.width - printed_chars;
	while (padding)
	{
		ft_putchar(' ');
		(*counter)++;
		padding--;
	}
	while (printed_chars)
	{
		ft_putchar(*str);
		(*counter)++;
		str++;
		printed_chars--;
	}
}

void	convert_x(t_flags flag, int num, int *counter)
{
	int	nbr_length;
}

int	get_printed_chars(int num)
{
	int	printed_chars = 0;

	if (num == -2147483648)
		return (10);
	if (num == 0)
		return (1);
	else if (num < 0)
		num = -num;
	while (num)
	{
		printed_chars++;
		num = num / 10;
	}
	return (printed_chars);
}

void	ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (num < 0)
	{
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

void	convert_d(t_flags flag, int num, int *counter)
{
	int	printed_chars;
	int	width_padding;
	int	prec_padding = 0;

	printed_chars = get_printed_chars(num);
	if (flag.precision_active && flag.precision > printed_chars)
		prec_padding = flag.precision - printed_chars;
	if (num < 0)
		printed_chars++;
	width_padding = flag.width - printed_chars - prec_padding;
	while (width_padding > 0)
	{
		ft_putchar(' ');
		(*counter)++;
		width_padding--;
	}
	if (num < 0)
	{
		ft_putchar('-');
	}
	while (prec_padding > 0)
	{
		ft_putchar('0');
		(*counter)++;
		prec_padding--;
	}
	ft_putnbr(num);
	*counter += printed_chars;
}

void	convert_it(t_flags flag, va_list *ap, int *counter)
{
	if (flag.type == 's')
		convert_s(flag, va_arg(*ap, char*), counter);
	if (flag.type == 'd')
		convert_d(flag, va_arg(*ap, int), counter);
	if (flag.type == 'x')
		convert_x(flag, va_arg(*ap, int), counter);
}

int	ft_printf(const char *fmt, ... )
{
	va_list	ap;
	t_flags	flag;
	int	counter;

	counter = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			flag = set_flags(&fmt);
			convert_it(flag, &ap, &counter);
		}
		else
		{
			ft_putchar(*fmt);
			fmt++;
			counter++;
		}
	}
	return (counter);
}

int	main(void)
{
	int	ret_value;

	ret_value = printf("REAL: ok'%20.4s' nice\n", "hello");
	printf("REAL: %d\n", ret_value);
	ret_value = ft_printf("MINE: ok'%20.4s' nice\n", "hello");
	printf("MINE: %d\n", ret_value);

	ret_value = printf("REAL: this num '%2d' is very '%4.5d'\n", 4, -1945);
	printf("READ: %d\n", ret_value);
	ret_value = ft_printf("MINE: this num '%2d' is very '%4.5d'\n", 4, -1945);
	printf("MINE: %d\n", ret_value);
}
