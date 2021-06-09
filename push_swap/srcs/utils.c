/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:28:31 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 13:31:23 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *head)
{
	int	len;
	t_stack	*curr_stack;

	len = 0;
	curr_stack = head->next;
	while (curr_stack)
	{
		len++;
		curr_stack = curr_stack->next;
	}
	return (len);
}

int	ft_check_order(t_stack *head1, t_stack *head2)
{
	t_stack	*tmp;

	tmp = head1->next;
	while (tmp)
	{
		if (tmp->next && tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	if (head2->next)
		return (0);
	return (1);
}

int	last_num(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->num);
}

int	has_unsorted(t_stack *head)
{
	t_part	*tmp_part;

	tmp_part = head->part_head->next;
	while (tmp_part)
	{
		if (tmp_part->sorted == 0)
			return (1);
		tmp_part = tmp_part->next;
	}
	return (0);
}
