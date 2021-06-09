/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:51 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 13:07:17 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_reverse_rot_a(t_stack *head1)
{
	t_stack	*first_tmp;
	t_stack	*tmp;

	first_tmp = head1->next;
	tmp = head1->next;
	while (tmp->next->next)
		tmp = tmp->next;
	head1->next = tmp->next;
	tmp->next = NULL;
	head1->next->next = first_tmp;
	return ("rra\n");
}

char	*ft_reverse_rot_b(t_stack *head2)
{
	t_stack	*first_tmp;
	t_stack	*tmp;

	first_tmp = head2->next;
	tmp = head2->next;
	while (tmp->next->next)
		tmp = tmp->next;
	head2->next = tmp->next;
	tmp->next = NULL;
	head2->next->next = first_tmp;
	return ("rrb\n");
}

char	*ft_rotate_a(t_stack *head1)
{
	t_stack	*first_tmp;
	t_stack *tmp;

	first_tmp = head1->next;
	head1->next = head1->next->next;
	tmp = head1->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_tmp;
	first_tmp->next = NULL;
	return ("ra\n");
}

char	*ft_rotate_b(t_stack *head2)
{
	t_stack	*first_tmp;
	t_stack *tmp;

	first_tmp = head2->next;
	head2->next = head2->next->next;
	tmp = head2->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_tmp;
	first_tmp->next = NULL;
	return ("rb\n");
}

