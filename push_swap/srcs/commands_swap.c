/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:02:35 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 13:06:24 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_push_a(t_stack *head1, t_stack *head2)
{
	t_stack	*first_tmp;

	if (head2->next)
	{
		first_tmp = head1->next;
		head1->next = head2->next;
		head2->next = head2->next->next;
		head1->next->next = first_tmp;
		return ("pa\n");
	}
	return ("");
}

char	*ft_push_b(t_stack *head1, t_stack *head2)
{
	t_stack	*first_tmp;

	if (head1->next)
	{
		first_tmp = head2->next;
		head2->next = head1->next;
		head1->next = head1->next->next;
		head2->next->next = first_tmp;
		return ("pb\n");
	}
	return ("");
}

char	*ft_swap_a(t_stack *head1)
{
	int	tmp;

	if (head1->next && head1->next->next)
	{
		tmp = head1->next->num;
		head1->next->num = head1->next->next->num;
		head1->next->next->num = tmp;
		return ("sa\n");
	}
	return (NULL);
}

char	*ft_swap_b(t_stack *head2)
{
	int	tmp;

	if (head2->next && head2->next->next)
	{
		tmp = head2->next->num;
		head2->next->num = head2->next->next->num;
		head2->next->next->num = tmp;
		return ("sb\n");
	}
	return (NULL);
}
