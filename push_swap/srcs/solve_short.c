/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:48:16 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 16:14:34 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_3(t_stack *head1)
{
	t_stack	*s;

	s = head1->next;
	if (s->next->next->num > s->num && s->num > s->next->num)
		ft_printf("%s", ft_swap_a(head1));
	else if (s->num > s->next->num && s->next->num > s->next->next->num)
	{
		ft_printf("%s", ft_swap_a(head1));
		ft_printf("%s", ft_reverse_rot_a(head1));
	}
	else if (s->num > s->next->next->num && s->next->next->num > s->next->num)
		ft_printf("%s", ft_rotate_a(head1));
	else if (s->next->num > s->next->next->num && s->next->next->num > s->num)
	{
		ft_printf("%s", ft_swap_a(head1));
		ft_printf("%s", ft_rotate_a(head1));
	}
	else if (s->next->num > s->num && s->num > s->next->next->num)
		ft_printf("%s", ft_reverse_rot_a(head1));
}

void	solve_5(t_stack *head1, t_stack *head2)
{
	int	rot_count;

	rot_count = 0;
	ft_printf("%s", ft_push_b(head1, head2));
	ft_printf("%s", ft_push_b(head1, head2));
	solve_3(head1);
	while (stack_len(head2))
	{
		if (head2->next->num < low_num(head1))
		{
			while (rot_count-- > 0)
				ft_printf("%s", ft_reverse_rot_a(head1));
			ft_printf("%s", ft_push_a(head1, head2));
			continue ;
		}
		if (head2->next->num > last_num(head1))
		{
			ft_printf("%s", ft_push_a(head1, head2));
			ft_printf("%s", ft_rotate_a(head1));
			continue ;
		}
		while (head2->next->num > head1->next->num)
		{
			ft_printf("%s", ft_rotate_a(head1));
			rot_count++;
			if (head2->next->num < head1->next->num)
			{
				ft_printf("%s", ft_push_a(head1, head2));
				break ;
			}
		}
		//ft_printf("%s", ft_push_a(head1, head2));
	}
	while (rot_count-- > 0)
		ft_printf("%s", ft_reverse_rot_a(head1));
}
