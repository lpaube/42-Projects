/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:21:24 by laube             #+#    #+#             */
/*   Updated: 2021/03/15 12:49:28 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (1)
	{
		if (str[index] == '\0')
		{
			return (str);
		}
		if (str[index] >= 'A' && str[index] <= 'Z')
		{
			str[index] = str[index] + 32;
		}
		else if (str[index] == '\0')
		{
			return (str);
		}
		index++;
	}
}
