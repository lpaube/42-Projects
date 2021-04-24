/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:21:44 by laube             #+#    #+#             */
/*   Updated: 2021/03/18 15:12:32 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isSpace(char c);
void	ft_isNegative(char c, int *sign);

int	ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	result;

	index = 0;
	sign = 1;
	result = 0;
	while (ft_isSpace(str[index]))
	{
		index++;
	}
	while (str[index] == '+' || str[index] == '-')
	{
		ft_isNegative(str[index], &sign);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	return (result * sign);
}

int	ft_isSpace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

void	ft_isNegative(char c, int *sign)
{
	if (c == '-')
		*sign *= -1;
}
