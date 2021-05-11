/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:41:28 by laube             #+#    #+#             */
/*   Updated: 2021/04/27 22:10:40 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (len-- > 0)
	{
		new_str[i++] = s[start++];
	}
	return (new_str);
}