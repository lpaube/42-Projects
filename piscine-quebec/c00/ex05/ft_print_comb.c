/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:58:11 by laube             #+#    #+#             */
/*   Updated: 2021/03/11 14:20:49 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_sending_nums(char a, char b, char c, bool notDone)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (notDone)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;
	bool	notDone;

	notDone = 1;
	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				notDone = !(a == '7' && b == '8' && c == '9');
				ft_sending_nums(a, b, c, notDone);
				c++;
			}
			b++;
		}
		a++;
	}
}
