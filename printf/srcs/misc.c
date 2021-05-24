/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:22:24 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 22:46:42 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	mod_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (ft_isdigit(str[counter]))
		counter++;
	return (counter);
}

int	free_it(void **mem, int free_state)
{
	if (free_state == 1)
	{
		free(*mem);
		*mem = NULL;
		return (1);
	}
	return (0);
}

