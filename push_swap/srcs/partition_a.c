/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:57:45 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 17:34:46 by laube            ###   ########.fr       */
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
	if (curr_part->amt == 2)
	{
		if (head1->next->num > head1->next->next->num)
			ft_printf("%s", ft_swap_a(head2));
	}
	len_og = curr_part->amt;
	while (i++ < len_og)
	{
		if (not_in_part(head1, 1, curr_part->midp))
			break ;
		if (head1->next->num < curr_part->midp)
		{
			ft_printf("%s", ft_push_b(head1, head2));
			counter++;
			curr_part->amt--;
		}
		else
		{
			ft_printf("%s", ft_rotate_a(head1));
			rot_count++;
		}
	}
	rev_rotation(head1, rot_count, 1);
	curr_part->sorted = part_midp(curr_part, head1, 1);
	return (counter);
}

void	sub_control_a(t_part *curr_part, t_stack *head1, t_stack *head2)
{
		curr_part->next = create_node_part();
		curr_part = curr_part->next;
		curr_part->amt = partitioning_a(head1, head2);
		curr_part->sorted = part_midp(curr_part, head2, 2);
		free_part(head1);
}

void	part_control_a(t_stack *head1, t_stack *head2)
{
	int		*arr;
	t_part	*curr_part;
	t_part	*tmp1;

	tmp1 = head1->part_head;
	while (tmp1->next)
		tmp1 = tmp1->next;
	if (tmp1->amt == 2 || tmp1->amt == 1)
	{
		if (tmp1->amt == 2 && head1->next->num > head1->next->next->num)
			ft_printf("%s", ft_swap_a(head1));
		tmp1->sorted = 1;
		return ;
	}
	curr_part = head2->part_head;
	while (curr_part->next)
		curr_part = curr_part->next;
	while (has_unsorted(head1) && stack_len(head1) > 2)
	{
		//sub_control_a(curr_part, head1, head2);
		curr_part->next = create_node_part();
		curr_part = curr_part->next;
		curr_part->amt = partitioning_a(head1, head2);
		curr_part->sorted = part_midp(curr_part, head2, 2);
		free_part(head1);
		if (head1->next->num > head1->next->next->num)
		{
			ft_printf("%s", ft_swap_a(head1));
			return ;
		}
	}
	if (stack_len(head1) == 2)
		head1->part_head->next->sorted = part_midp(head1->part_head->next, head1, 1);
}
