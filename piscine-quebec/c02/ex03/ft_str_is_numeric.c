/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:15:09 by laube             #+#    #+#             */
/*   Updated: 2021/03/16 11:30:13 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	index;

	index = 0;
	while (1)
	{
		if (str[index] >= '0' && str[index] <= '9')
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
