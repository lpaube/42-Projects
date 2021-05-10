/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:12:00 by laube             #+#    #+#             */
/*   Updated: 2021/05/10 18:15:34 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
			res = (char *)s;
		s++;
	}
	if (*s == c)
		res = (char *)s;
	if (res)
		return (res);
	return (NULL);

}
