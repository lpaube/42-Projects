/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:08:59 by laube             #+#    #+#             */
/*   Updated: 2021/04/26 23:27:54 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;

	len = 0;
	str = malloc(ft_strlen(s) * sizeof(char));
	if !(str)
		return (NULL);
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len++;
	while (s[len] && s[len] != ' ' && s[len] != '\n' && s[len] != '\t')
		len++;
	str = malloc(len * sizeof(char));
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s && *s != ' ' && *s != '\n' && *s != '\t')
	{
		*str = *s;
		str++;
		s++;
	}
	*str = '\0';
	return (str);
}
