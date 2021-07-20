/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:33:34 by laube             #+#    #+#             */
/*   Updated: 2021/05/11 16:56:13 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			if (len - i <= 0)
				return (NULL);
			i++;
			if (needle[i] == 0)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
