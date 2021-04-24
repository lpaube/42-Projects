/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:53:29 by laube             #+#    #+#             */
/*   Updated: 2021/03/23 15:13:14 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src);

char	*ft_strdup(char *src)
{
	int		index;
	char	*dest;

	index = 0;
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	ft_strlen(char *src)
{
	int	index;

	index = 0;
	while (src[index])
		index++;
	return (index);
}
