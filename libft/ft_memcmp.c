/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:42:28 by laube             #+#    #+#             */
/*   Updated: 2021/05/10 16:34:19 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s2;
	while (n--)
	{
		if (*a > *b)
			return (*a - *b);
		if (*a < *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}
