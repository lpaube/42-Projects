/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:17:48 by laube             #+#    #+#             */
/*   Updated: 2021/03/18 19:17:40 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index;

	index = 0;
	if (to_find[0] == 0)
		return (str);
	while (*str != 0)
	{
		while (str[index] == to_find[index] && str[index] != 0)
		{
			index++;
			if (to_find[index] == 0)
				return (str);
		}
		str++;
		index = 0;
	}
	return (0);
}
