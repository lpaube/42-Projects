/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:48:16 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 22:40:49 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_3(t_stack *head1)
{
	t_stack	*s;

	s = head1->next;
	if (s->next->next->num > s->num && s->num > s->next->num)
		ft_putstr_fd(ft_swap_a(head1), 1);
	else if (s->num > s->next->num && s->next->num > s->next->next->num)
	{
		ft_putstr_fd(ft_swap_a(head1), 1);
		ft_putstr_fd(ft_reverse_rot_a(head1), 1);
	}
	else if (s->num > s->next->next->num && s->next->next->num > s->next->num)
		ft_putstr_fd(ft_rotate_a(head1), 1);
	else if (s->next->num > s->next->next->num && s->next->next->num > s->num)
	{
		ft_putstr_fd(ft_swap_a(head1), 1);
		ft_putstr_fd(ft_rotate_a(head1), 1);
	}
	else if (s->next->num > s->num && s->num > s->next->next->num)
		ft_putstr_fd(ft_reverse_rot_a(head1), 1);
}

int	it_fits(t_stack *head1, t_stack *head2)
{
	t_stack	*h1;
	t_stack	*h2;

	h1 = head1->next;
	h2 = head2->next;
	if (h2->num < h1->num && h1->num == low_num(head1))
	{
		return (1);
	}
	if (h1->num > h2->num && last_num(head1) < h2->num)
	{
		return (1);
	}
	if (h2->num > high_num(head1) && h1->num == low_num(head1))
	{
		return (1);
	}
	return (0);
}

void	rot_revrot(t_stack *head)
{
	int	i;
	int	*arr;
	int	len;

	len = stack_len(head);
	arr = stack_to_arr(head, len);
	i = 0;
	while (i < len)
	{
		if (arr[i] == low_num(head))
			break ;
		i++;
	}
	if (i <= 2)
		ft_putstr_fd(ft_rotate_a(head), 1);
	else if (i > 2)
		ft_putstr_fd(ft_reverse_rot_a(head), 1);
}

void	solve_5(t_stack *head1, t_stack *head2)
{
	int	rot_count;

	rot_count = 0;
	ft_putstr_fd(ft_push_b(head1, head2), 1);
	ft_putstr_fd(ft_push_b(head1, head2), 1);
	solve_3(head1);
	while (stack_len(head2))
	{
		if (it_fits(head1, head2))
			ft_putstr_fd(ft_push_a(head1, head2), 1);
		else
		{
			ft_putstr_fd(ft_rotate_a(head1), 1);
			rot_count++;
		}
		if (ft_check_order(head1, head2))
			return ;
	}
	while (ft_check_order(head1, head2) != 1)
		rot_revrot(head1);
}
