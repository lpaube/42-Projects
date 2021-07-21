/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:25:00 by laube             #+#    #+#             */
/*   Updated: 2021/07/20 20:32:25 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	char	*str_og;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len * sizeof(char));
	str_og = str;
	if (!str)
		return (NULL);
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	while (*s2)
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = '\0';
	return (str_og);
}
