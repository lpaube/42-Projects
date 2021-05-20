/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:07:34 by laube             #+#    #+#             */
/*   Updated: 2021/05/15 17:21:41 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_expo(int base, int expo);
static int	ft_intlen(int n);
static void	ft_checkneg(int *n, int *intlen, char *str, int *i);

char	*ft_itoa(int n)
{
	char	*str;
	int		intlen;
	int		i;

	i = 0;
	intlen = ft_intlen(n);
	str = malloc((intlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		ft_checkneg(&n, &intlen, str, &i);
	while (intlen > 1)
	{
		str[i] = (n / ft_expo(10, intlen - 1)) + '0';
		n = n % ft_expo(10, intlen - 1);
		intlen--;
		i++;
	}
	str[i] = n + '0';
	i++;
	str[i] = '\0';
	return (str);
}

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	ft_expo(int base, int expo)
{
	int	res;

	if (expo == 0)
		return (1);
	res = base;
	while (expo > 1)
	{
		res = res * base;
		expo--;
	}
	return (res);
}

static void	ft_checkneg(int *n, int *intlen, char *str, int *i)
{
	if (*n == -2147483648)
	{
		str[*i] = '-';
		*i = *i + 1;
		str[*i] = '2';
		*i = *i + 1;
		*intlen = *intlen - 2;
		*n = 147483648;
	}
	else
	{
		*n = -1 * *n;
		str[*i] = '-';
		*i = *i + 1;
		*intlen = *intlen - 1;
	}
}
