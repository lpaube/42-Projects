#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_numlen(long long num, int base_len)
{
	unsigned int len = 1;

	while (num >= base_len)
	{
		len++;
		num /= base_len;
	}
	return (len);
}

void	ft_putnbr(long long num, int base_len, char *base)
{
	char	c;

	if (num >= base_len)
		ft_putnbr(num / base_len, base_len, base);
	c = base[(num % base_len)];
	//printf("char: %c\n", c);
	write(1, &c, 1);
}

int	ft_printf(const char *fmt, ... )
{
	int prec = 0, zeros = 0, spaces = 0, width = 0, prec_len = 0,
		len = 0, base_len = 0, negative = 0, ret = 0;
	va_list	list;
	char	*str;
	char	*base;
	long long num = 0;
	void	*addr;

	va_start(list, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			zeros = 0, spaces = 0, width = 0, prec_len = 0, len = 0, base_len = 0,
				  negative = 0;
			while (*fmt >= '0' && *fmt <= '9')
			{
				width = width * 10 + (*fmt - '0');
				fmt++;
			}
			if (*fmt == '.')
			{
				prec = 1;
				fmt++;
				while (*fmt >= '0' && *fmt <= '9')
				{
					prec_len = prec_len * 10 + (*fmt - '0');
					fmt++;
				}
			}
			if (*fmt == 's')
			{
				str = va_arg(list, char *);
				if (!str)
					str = "(null)";
				len = ft_strlen(str);
			}
			if (*fmt == 'd')
			{
				base_len = 10;
				base = "0123456789";
				num = va_arg(list, int);
				if (num < 0)
				{
					negative = 1;
					num = -num;
				}
				len = ft_numlen(num, base_len);
			}
			if (*fmt == 'x')
			{
				base_len = 16;
				base = "0123456789abcdef";
				num = va_arg(list, unsigned int);
				len = ft_numlen(num, base_len);
			}
			if (*fmt == 'p')
			{
				base_len = 16;
				base = "0123456789abcdef";
				num = (unsigned long long)va_arg(list, void *);
				len = ft_numlen(num, base_len) + 2;
			}
			if (prec)
			{
				if (prec_len > len && *fmt != 's')
					zeros = prec_len - len;
				if (prec_len < len && *fmt == 's')
					len = prec_len;
				if (!prec_len && !num)
					len = 0;
			}
			spaces = width - zeros - len - negative;

			while (spaces-- > 0)
			{
				write(1, " ", 1);
				ret++;
			}
			if (negative)
			{
				write(1, "-", 1);
				ret++;
			}
			while (zeros-- > 0)
			{
				write(1, "0", 1);
				ret++;
			}
			if (*fmt == 'p')
				write(1, "0x", 2);
			if (*fmt == 's')
				write(1, str, len);
			else if (len)
			{
				//printf("num: %lld\n", num);
				ft_putnbr(num, base_len, base);
			}
			ret += len;
		}
		else
		{
			write(1, &*fmt, 1);
			ret++;
		}
		fmt++;
	}
	va_end(list);
	return (ret);
}

int	main(void)
{
	int	ret;
	char *sss = "ok lol";
	ret = printf("REAL: num: %d str: %s ptr: %p hex: %x\n", -15, "whatf", sss, 36);
	printf("REAL: ret: %d\n", ret);

	ret = ft_printf("MINE: num: %d str: %s ptr: %p hex: %x\n", -15, "whatf", sss, 36);
	printf("MINE: ret: %d\n", ret);
}
