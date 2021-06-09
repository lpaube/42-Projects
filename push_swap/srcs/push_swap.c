/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:19 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 13:52:52 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stacks(t_stack *head1, t_stack *head2)
{
	t_stack	*tmp;

	tmp = head1->next;
	ft_printf("Stack A: ");
	while (tmp)
	{
		ft_printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	ft_printf("\n");
	tmp = head2->next;
	ft_printf("Stack B: ");
	while (tmp)
	{
		ft_printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_algo_control(t_stack *head1, t_stack *head2, int len)
{
	int	*arr;
	int	midpoint;
	int	i;
	
	i = 0;
	while (ft_check_order(head1, head2) != 1)
	{
		i++;
		if (i == 1 && stack_len(head1) == 3 || stack_len(head1) == 5)
		{
			if (stack_len(head1) == 3)
				solve_3(head1);
			else if (stack_len(head1) == 5)
				solve_5(head1, head2);
			return ;
		}
		part_control_a(head1, head2);
		part_control_b(head1, head2);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*head1;
	t_stack *head2;
	int		len;

	head1 = ft_build_stack(argv);
	head2 = ft_create_node();
	head2->part_head = create_node_part();
	len = stack_len(head1);

	ft_algo_control(head1, head2, len);
}
