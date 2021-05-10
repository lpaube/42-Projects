/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:55:05 by laube             #+#    #+#             */
/*   Updated: 2021/05/10 17:46:52 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	limit;
	size_t	dst_len;
	int		src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	limit = dstsize - ft_strlen(dst) - 1;
	while (*dst != 0)
		dst++;
	while (*src && limit--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (dst_len + src_len);
}
