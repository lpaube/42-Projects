/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:56:22 by laube             #+#    #+#             */
/*   Updated: 2021/05/10 13:56:11 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	while (n > 0)
	{
		*b = *a;
		if (*b == c)
			return (b + 1);
		a++;
		b++;
		n--;
	}
	return (dst);
}
