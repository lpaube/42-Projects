/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:19 by laube             #+#    #+#             */
/*   Updated: 2021/05/25 23:44:58 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_push_a(t_stack *stack1, t_stack *stack2)
{
	int	i;

	i = stack1->stack_len - 1;
	while (i > 0)
	{
		stack1->stack[i] = stack1->stack[i - 1];
		i--;
	}
	stack1->stack[0] = stack2->stack[0];
	stack1->stack_len++;
	while (i < stack2->stack_len - 1)
	{
		stack2->stack[i] = stack2->stack[i + 1];
		i++;
	}
	stack2->stack[i] = 0;
	stack2->stack_len--;
	return ("pa\n");
}

char	*ft_swap_b(t_stack *stack2)
{
	int	tmp;

	if (stack2->stack_len <= 1)
		return ("");;
	tmp = stack2->stack[0];
	stack2->stack[0] = stack2->stack[1];
	stack2->stack[1] = tmp;
	return ("sb\n");
}

char	*ft_swap_a(t_stack *head1)
{
	int	tmp;
}

char	*ft_swap_s(t_stack *head1, t_stack *head2)
{
	ft_swap_a(stack1);
	ft_swap_b(stack2);
	return ("ss\n");
}


void	ft_algo_control(char *stack1, char *stack2)
{
	
}

t_stack	*ft_create_node(void)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->num = 0;
	node->next = NULL;
	return (node);
}

t_stack	*ft_build_stack(char **argv)
{
	t_stack	*head1;
	t_stack	*tmp;
	int		i;

	i = 1;
	head1 = ft_create_node();
	tmp = head1;
	while (argv[i])
	{
		tmp->next = create_node();
		tmp = tmp->next;
		tmp->num = ft_atoi(argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*head1;
	t_stack *head2;

	head1 = ft_build_stack(argv);
	head2 = NULL;
	ft_algo_control(&stack1, &stack2);
}
