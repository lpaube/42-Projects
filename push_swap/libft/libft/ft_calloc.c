/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:03:29 by laube             #+#    #+#             */
/*   Updated: 2021/05/22 16:11:42 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*pointing;
	size_t		i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	i = 0;
	pointing = malloc(size * count);
	if (!pointing)
		return (NULL);
	while (i < (size * count))
	{
		((char *)pointing)[i++] = 0;
	}
	return (pointing);
}
