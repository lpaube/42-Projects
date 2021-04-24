/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:44:28 by laube             #+#    #+#             */
/*   Updated: 2021/03/18 19:05:27 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (s1[index] != '\0' && index < n)
	{
		if (s2[index] == '\0')
			return (1);
		if (s2[index] > s1[index])
			return (-1);
		if (s1[index] > s2[index])
			return (1);
		index++;
	}
	if (s2[index] != '\0' && s1[index] == '\0')
		return (-1);
	return (0);
}
