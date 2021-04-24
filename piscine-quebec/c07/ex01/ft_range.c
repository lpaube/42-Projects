/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:19:08 by laube             #+#    #+#             */
/*   Updated: 2021/03/22 18:37:30 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	*range0;

	if (min >= max)
	{
		range = 0;
		return (range);
	}
	range = malloc((max - min) * sizeof(int));
	range0 = range;
	while (max > min)
	{
		*range = min++;
		range++;
	}
	return (range0);
}
