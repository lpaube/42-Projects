/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:08:58 by laube             #+#    #+#             */
/*   Updated: 2021/05/15 16:58:09 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*big;
	size_t		len;

	len = 0;
	big = (const char *)s;
	while (len < n)
	{
		if ((unsigned char)big[len] == (unsigned char)c)
			return ((void *)&big[len]);
		len++;
	}
	return (NULL);
}
