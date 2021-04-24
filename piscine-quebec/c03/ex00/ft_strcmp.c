/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:59:48 by laube             #+#    #+#             */
/*   Updated: 2021/03/16 14:10:11 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (s2[index] == '\0')
			return (s1[index] - s2[index]);
		if (s2[index] > s1[index])
			return (-(s2[index] - s1[index]));
		if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	if (s2[index] != '\0')
		return (-(s2[index] - s1[index]));
	return (0);
}
