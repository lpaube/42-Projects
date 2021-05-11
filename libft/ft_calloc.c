/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:03:29 by laube             #+#    #+#             */
/*   Updated: 2021/05/11 13:03:36 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*pointing;
	size_t		i;

	i = 0;
	pointing = malloc(size * count);
	while (i < (size * count))
	{
		((char *)pointing)[i++] = 0;
	}
	return (pointing);
}
