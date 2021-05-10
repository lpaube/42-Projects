/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:08:58 by laube             #+#    #+#             */
/*   Updated: 2021/05/10 15:42:08 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*res;

	while (n--)
	{
		if (*((char *)s) == c)
		{
			res = (char *)s;
			return (res);
		}
		s = (char *)s + 1;
	}
	return (NULL);
}
