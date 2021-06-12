/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:57:45 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 22:42:33 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	partitioning_a(t_stack *head1, t_stack *head2)
{
	int		i;
	int		counter;
	int		len_og;
	int		rot_count;
	t_part	*curr_part;

	rot_count = 0;
	i = 0;
	counter = 0;
	curr_part = head1->part_head->next;
	while (curr_part->next)
		curr_part = curr_part->next;
	len_og = curr_part->amt;
	while (i++ < len_og)
		counter += sub_a(head1, head2, curr_part, &rot_count);
	rev_rotation(head1, rot_count, 1);
	curr_part->sorted = part_midp(curr_part, head1, 1);
	return (counter);
}

t_part	*sub_control_a(t_part *curr_part, t_stack *head1, t_stack *head2)
{
	curr_part->next = create_node_part();
	curr_part = curr_part->next;
	curr_part->amt = partitioning_a(head1, head2);
	curr_part->sorted = part_midp(curr_part, head2, 2);
	free_part(head1);
	return (curr_part);
}

void	len_is_2(t_stack *head1)
{
	t_part	*part;

	part = head1->part_head;
	if (stack_len(head1) == 2)
		part->next->sorted = part_midp(part->next, head1, 1);
}

void	amt_is_2(t_stack *head1, t_part *tmp1)
{
	if (tmp1->amt == 2 && head1->next->num > head1->next->next->num)
		ft_putstr_fd(ft_swap_a(head1), 1);
	tmp1->sorted = 1;
}

void	part_control_a(t_stack *head1, t_stack *head2)
{
	t_part	*curr_part;
	t_part	*tmp1;

	tmp1 = head1->part_head;
	while (tmp1->next)
		tmp1 = tmp1->next;
	if (tmp1->amt == 2 || tmp1->amt == 1)
	{
		amt_is_2(head1, tmp1);
		return ;
	}
	curr_part = head2->part_head;
	while (curr_part->next)
		curr_part = curr_part->next;
	while (has_unsorted(head1) && stack_len(head1) > 2)
	{
		curr_part = sub_control_a(curr_part, head1, head2);
		if (head1->next->num > head1->next->next->num)
		{
			ft_putstr_fd(ft_swap_a(head1), 1);
			return ;
		}
	}
	len_is_2(head1);
}
