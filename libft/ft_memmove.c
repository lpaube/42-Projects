/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:03:01 by laube             #+#    #+#             */
/*   Updated: 2021/05/10 14:48:04 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		strlen;
	void	*dst_og;
	int		i;

	i = 0;
	strlen = ft_strlen((char *)dst);
	dst_og = malloc((strlen + 1) * sizeof(char));
	while (i < strlen)
	{
		((char *)dst_og)[i] = ((char *)dst)[i];
		i++;
	}
	ft_memcpy(dst, src, len);
	return (dst_og);
}
