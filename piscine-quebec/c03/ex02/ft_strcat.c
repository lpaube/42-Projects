/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:08:10 by laube             #+#    #+#             */
/*   Updated: 2021/03/16 19:38:52 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	indexDest;
	int	indexSrc;

	indexDest = 0;
	indexSrc = 0;
	while (dest[indexDest] != 0)
	{
		indexDest++;
	}
	while (src[indexSrc] != 0)
	{
		dest[indexDest] = src[indexSrc];
		indexDest++;
		indexSrc++;
	}
	dest[indexDest] = 0;
	return (dest);
}
