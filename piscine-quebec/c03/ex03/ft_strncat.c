/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:23:26 by laube             #+#    #+#             */
/*   Updated: 2021/03/17 14:16:32 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	indexDest;
	unsigned int	indexSrc;

	indexDest = 0;
	indexSrc = 0;
	while (dest[indexDest] != 0)
	{
		indexDest++;
	}
	while (src[indexSrc] != 0 && indexSrc < nb)
	{
		dest[indexDest] = src[indexSrc];
		indexDest++;
		indexSrc++;
	}
	dest[indexDest] = 0;
	return (dest);
}
