/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:29:39 by laube             #+#    #+#             */
/*   Updated: 2021/05/04 17:44:51 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		if (s2[i] > s1[i])
			return (-(s2[i] - s1[i]));
		i++;
	}
	if (s2[i] != 0 && i < n)
		return (-(s2[i] - s1[i]));
	else
		return (0);
}
