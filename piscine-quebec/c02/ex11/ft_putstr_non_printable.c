/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:17:02 by laube             #+#    #+#             */
/*   Updated: 2021/03/16 13:06:20 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_toHex(char c);
void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 32 && str[index] <= 127)
		{
			ft_putchar(str[index]);
		}
		else
		{
			ft_toHex(str[index]);
		}
		index++;
	}
}

void	ft_toHex(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
