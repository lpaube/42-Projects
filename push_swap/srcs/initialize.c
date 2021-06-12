/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:20:17 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 16:20:29 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_part	*create_node_part(void)
{
	t_part	*node;

	node = (t_part *)malloc(sizeof(t_part));
	node->amt = 0;
	node->midp = 0;
	node->sorted = 0;
	node->next = NULL;
	return (node);
}

t_stack	*ft_create_node(void)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->num = 0;
	node->next = NULL;
	node->part_head = NULL;
	return (node);
}

void	init_part1(t_stack *head1)
{
	t_part	*part;
	int		*arr;

	head1->part_head->next = create_node_part();
	part = head1->part_head->next;
	part->amt = stack_len(head1);
	arr = stack_to_arr(head1, stack_len(head1));
	arr_quicksort_control(arr, 0, stack_len(head1) - 1);
	part->midp = arr[stack_len(head1) / 2];
}

t_stack	*ft_build_stack(char **argv)
{
	t_stack	*head1;
	t_stack	*tmp;
	int		i;

	i = 0;
	head1 = ft_create_node();
	head1->part_head = create_node_part();
	tmp = head1;
	while (argv[i])
	{
		tmp->next = ft_create_node();
		tmp = tmp->next;
		tmp->num = ft_atoi(argv[i]);
		i++;
	}
	init_part1(head1);
	return (head1);
}
