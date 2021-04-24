/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:29:59 by laube             #+#    #+#             */
/*   Updated: 2021/03/14 18:56:18 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	index;
	int	counter;
	int	tmp;

	index = 0;
	counter = 0;
	while (index < size)
	{
		tmp = tab[index];
		while (counter < size)
		{
			if (tab[index] < tab[counter])
			{
				tmp = tab[counter];
				tab[counter] = tab[index];
				tab[index] = tmp;
				index--;
				break ;
			}
			counter++;
		}
		counter = 0;
		index++;
	}
}
