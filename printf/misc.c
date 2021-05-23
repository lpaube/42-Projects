/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:22:24 by laube             #+#    #+#             */
/*   Updated: 2021/05/23 16:22:48 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (ft_isdigit(str[counter]))
		counter++;
	return (counter);
}
