/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:46:28 by laube             #+#    #+#             */
/*   Updated: 2021/03/19 13:00:25 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	indexDest;
	unsigned int	indexSrc;
	unsigned int	destLen;

	destLen = ft_strlen(dest);
	indexDest = destLen;
	indexSrc = 0;
	destLen = indexDest;
	while (src[indexSrc] != 0 && indexDest < size - 1)
	{
		dest[indexDest] = src[indexSrc];
		indexDest++;
		indexSrc++;
	}
	dest[indexDest] = 0;
	while (src[indexSrc] != 0)
	{
		indexSrc++;
	}
	if (size > indexSrc)
		return (destLen + indexSrc);
	return (destLen + size + 1);
}

unsigned int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}
