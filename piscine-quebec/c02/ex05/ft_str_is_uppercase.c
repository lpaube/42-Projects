/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:30:48 by laube             #+#    #+#             */
/*   Updated: 2021/03/16 11:56:51 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	index;

	index = 0;
	while (1)
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
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
