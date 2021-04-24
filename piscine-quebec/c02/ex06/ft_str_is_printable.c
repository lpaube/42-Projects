/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:37:10 by laube             #+#    #+#             */
/*   Updated: 2021/03/15 11:53:07 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	index;

	index = 0;
	while (1)
	{
		if (str[index] >= 32 && str[index] <= 127)
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
