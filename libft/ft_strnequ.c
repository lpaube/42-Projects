/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:36:25 by laube             #+#    #+#             */
/*   Updated: 2021/04/18 12:39:12 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && n > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		n--;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
