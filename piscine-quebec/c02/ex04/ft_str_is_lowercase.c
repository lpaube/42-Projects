/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:20:44 by laube             #+#    #+#             */
/*   Updated: 2021/03/15 11:24:16 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	index;

	index = 0;
	while (1)
	{
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			index++;
		}
		else
		{
			if (str[index] == '\0')
			{
				return (1);
			}
			return (0);
		}
	}
}
