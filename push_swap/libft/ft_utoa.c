/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:07:34 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 23:11:33 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static unsigned int	ft_expo(unsigned int base, unsigned int expo)
{
	unsigned int	res;

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

char	*ft_utoa(unsigned int n)
{
	char			*str;
	int unsigned	intlen;
	int unsigned	i;

	i = 0;
	intlen = ft_intlen(n);
	str = malloc((intlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
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
