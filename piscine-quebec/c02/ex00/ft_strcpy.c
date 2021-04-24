/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:12:55 by laube             #+#    #+#             */
/*   Updated: 2021/03/15 18:44:39 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (1)
	{
		dest[index] = src[index];
		if (src[index] == '\0')
		{
			break ;
		}
		index++;
	}
	return (dest);
}
