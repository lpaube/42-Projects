/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:01:15 by laube             #+#    #+#             */
/*   Updated: 2021/07/11 17:26:38 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top_row(int j, int x)
{
	if (j == 0)
		ft_putchar('A');
	else if (j != x - 1)
		ft_putchar('B');
	else
		ft_putchar('A');
}

void	mid_row(int j, int x)
{
	if (j == 0)
		ft_putchar('B');
	else if (j != x - 1)
		ft_putchar(' ');
	else
		ft_putchar('B');
}

void	bot_row(int j, int x)
{
	if (j == 0)
		ft_putchar('C');
	else if (j != x - 1)
		ft_putchar('B');
	else
		ft_putchar('C');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0)
				top_row(j, x);
			else if (i != y - 1)
				mid_row(j, x);
			else
				bot_row(j, x);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
