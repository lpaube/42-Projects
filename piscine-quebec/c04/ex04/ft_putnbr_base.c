/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:13:21 by laube             #+#    #+#             */
/*   Updated: 2021/03/18 18:11:59 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isValidBase(char *base);
void	ft_putchar(char c);
void	ft_nbrRecursive(int nbr, char *base, int len);

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_isValidBase(base);
	if (ft_isValidBase(base) == 0)
		return ;
	ft_nbrRecursive(nbr, base, len);
}

void	ft_nbrRecursive(int nbr, char *base, int len)
{
	if (nbr == -2147483648)
	{
		ft_nbrRecursive(nbr / len, base, len);
		ft_putchar(base[-(nbr % len)]);
		return ;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_nbrRecursive(-nbr, base, len);
		return ;
	}
	if (nbr >= len)
	{
		ft_nbrRecursive(nbr / len, base, len);
		ft_nbrRecursive(nbr % len, base, len);
	}
	if (nbr < len)
	{
		ft_putchar(base[nbr]);
	}
}

int	ft_isValidBase(char *base)
{
	int	index;
	int	counter;

	index = 0;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[index])
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		counter = index + 1;
		while (base[counter])
		{
			if (base[index] == base[counter])
			{
				return (0);
			}
			counter++;
		}
		index++;
	}
	return (index);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
