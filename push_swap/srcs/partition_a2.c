/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:46:54 by laube             #+#    #+#             */
/*   Updated: 2021/06/10 22:19:52 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sub_a(t_stack *h1, t_stack *h2, t_part *curr_part, int *rot_count)
{
	int	counter;

	counter = 0;
	if (not_in_part(h1, 1, curr_part->midp))
		return (0);
	if (h1->next->num < curr_part->midp)
	{
		ft_printf("%s", ft_push_b(h1, h2));
		counter++;
		curr_part->amt--;
	}
	else
	{
		ft_printf("%s", ft_rotate_a(h1));
		(*rot_count)++;
	}
	return (counter);
}
