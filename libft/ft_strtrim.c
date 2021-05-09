/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:08:59 by laube             #+#    #+#             */
/*   Updated: 2021/05/06 13:23:59 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	is_member(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	max_len(char const *s1, char const *set)
{
	int	len;
	int	max_len;

	len = 0;
	max_len = 0;
	while (s1[len])
	{
		max_len = 0;
		while (is_member(s1[len + max_len], set))
		{
			max_len++;
			if (s1[len + max_len] == 0)
			{
				return (len);
			}
		}
		len++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		maxlen;

	len = 0;
	while (is_member(*s1, set))
		s1++;
	maxlen = max_len(s1, set);
	str = malloc((maxlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (len < maxlen && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
