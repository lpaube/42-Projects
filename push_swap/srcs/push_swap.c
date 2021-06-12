/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:19 by laube             #+#    #+#             */
/*   Updated: 2021/06/10 21:13:49 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all_parts(t_stack *head)
{
	t_part	*tmp_part;
	t_part	*tmp_head;

	tmp_head = head->part_head;
	while (tmp_head != NULL)
	{
		tmp_part = tmp_head;
		tmp_head = tmp_head->next;
		free(tmp_part);
		tmp_part = NULL;
	}
}

void	free_stack(t_stack *head)
{
	t_stack	*tmp_stack;

	free_all_parts(head);
	while (head != NULL)
	{
		tmp_stack = head;
		head = head->next;
		free(tmp_stack);
		tmp_stack = NULL;
	}
}

void	ft_print_stacks(t_stack *head1, t_stack *head2)
{
	t_stack	*tmp;

	tmp = head1->next;
	ft_putstr_fd("Stack A: ", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->num, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
	tmp = head2->next;
	ft_putstr_fd("Stack B: ", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->num, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_algo_control(t_stack *head1, t_stack *head2)
{
	int	i;

	i = 0;
	while (ft_check_order(head1, head2) != 1)
	{
		i++;
		if (i == 1 && (stack_len(head1) == 3 || stack_len(head1) == 5))
		{
			if (stack_len(head1) == 3)
				solve_3(head1);
			else if (stack_len(head1) == 5)
				solve_5(head1, head2);
			continue ;
		}
		part_control_a(head1, head2);
		part_control_b(head1, head2);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*head1;
	t_stack	*head2;
	int		free_state;

	free_state = 0;
	argv++;
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		free_state = 1;
	}
	if (check_errors(argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	head1 = ft_build_stack(argv);
	head2 = ft_create_node();
	head2->part_head = create_node_part();
	ft_algo_control(head1, head2);
	free_stack(head1);
	free_stack(head2);
	if (free_state)
		free(argv);
}
