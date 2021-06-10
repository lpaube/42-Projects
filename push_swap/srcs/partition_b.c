/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:00:35 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 22:45:26 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sub_b(t_stack *head1, t_stack *head2, t_part *curr_part, int *rotc)
{
	int	counter;

	counter = 0;
	if (not_in_part(head2, 2, curr_part->midp))
		return (0);
	if (head2->next->num > curr_part->midp)
	{
		ft_printf("%s", ft_push_a(head1, head2));
		counter++;
		curr_part->amt--;
	}
	else
	{
		ft_printf("%s", ft_rotate_b(head2));
		(*rotc)++;
	}
	return (counter);
}

int	sub_parting_b(t_stack *head1, t_stack *head2, t_part *curr_part)
{
	int	counter;

	counter = 0;
	if (curr_part->sorted == 1)
	{
		while (curr_part->amt)
		{
			ft_printf("%s", ft_push_a(head1, head2));
			curr_part->amt--;
			counter++;
		}
	}
	if (curr_part->amt == 2)
	{
		if (head2->next->num < head2->next->next->num)
			ft_printf("%s", ft_swap_b(head2));
		ft_printf("%s", ft_push_a(head1, head2));
		ft_printf("%s", ft_push_a(head1, head2));
		counter += 2;
		curr_part->amt -= 2;
	}
	return (counter);
}

int	partitioning_b(t_stack *head1, t_stack *head2)
{
	int		i;
	int		counter;
	int		len_og;
	t_part	*curr_part;
	int		rot_count;

	i = 0;
	counter = 0;
	rot_count = 0;
	curr_part = head2->part_head;
	while (curr_part->next)
		curr_part = curr_part->next;
	counter += sub_parting_b(head1, head2, curr_part);
	len_og = curr_part->amt;
	while (i++ < len_og)
		counter += sub_b(head1, head2, curr_part, &rot_count);
	rev_rotation(head2, rot_count, 2);
	curr_part->sorted = part_midp(curr_part, head2, 2);
	return (counter);
}

void	part_control_b(t_stack *head1, t_stack *head2)
{
	t_part	*curr_part;

	curr_part = head1->part_head;
	while (curr_part->next)
		curr_part = curr_part->next;
	while (stack_len(head2) && !has_unsorted(head1))
	{
		curr_part->next = create_node_part();
		curr_part = curr_part->next;
		curr_part->amt = partitioning_b(head1, head2);
		curr_part->sorted = part_midp(curr_part, head1, 1);
		free_part(head2);
	}
}
