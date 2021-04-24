/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:50:39 by laube             #+#    #+#             */
/*   Updated: 2021/03/17 14:02:15 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	int				counter;

	counter = 0;
	index = 0;
	if (size > 0)
	{
		while (index < size - 1)
		{
			if (src[index] == '\0')
			{
				break ;
			}
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (1)
	{
		counter++;
		if (src[counter] == '\0')
			return (counter);
	}
}
