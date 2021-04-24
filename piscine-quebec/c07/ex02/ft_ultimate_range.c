/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:36:49 by laube             #+#    #+#             */
/*   Updated: 2021/03/23 11:00:49 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	minog;

	minog = min;
	index = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (range == 0)
	{
		*range = 0;
		return (-1);
	}
	while (min < max)
	{
		(*range)[index] = min++;
		index++;
	}
	return (max - minog);
}
