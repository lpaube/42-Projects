/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:46:54 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 20:47:58 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sub_a(t_stack *head1, t_stack *head2, t_part *curr_part, int *rot_count)
{
	int	counter;

	counter = 0;
	if (not_in_part(head1, 1, curr_part->midp))
		return (0);
	if (head1->next->num < curr_part->midp)
	{
		ft_printf("%s", ft_push_b(head1, head2));
		counter++;
		curr_part->amt--;
	}
	else
	{
		ft_printf("%s", ft_rotate_a(head1));
		(*rot_count)++;
	}
	return (counter);
}
