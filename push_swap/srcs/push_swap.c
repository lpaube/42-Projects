/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:19 by laube             #+#    #+#             */
/*   Updated: 2021/05/26 22:59:29 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

t_stack	*ft_last_node(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->next;
	if (!tmp)
		return (head);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);

}

int	ft_check_order(t_stack *head1, t_stack *head2)
{
	int	ordered = 1;
	t_stack	*tmp;

	tmp = head1->next;
	while (tmp)
	{
		if (tmp->next && tmp->num > tmp->next->num)
			ordered = 0;
		tmp = tmp->next;
	}
	if (head2->next)
		ordered = 0;
	return (ordered);
}


void	ft_print_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->next;
	printf("Stack: ");
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}
void	ft_print_stacks(t_stack *head1, t_stack *head2)
{
	t_stack	*tmp;

	tmp = head1->next;
	printf("Stack A: ");
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = head2->next;
	printf("Stack B: ");
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

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
	return ("rra\n");
}

char	*ft_reverse_rot_r(t_stack *head1, t_stack *head2)
{
	ft_reverse_rot_a(head1);
	ft_reverse_rot_b(head2);
	return ("rrr\n");
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
	head2 = head2->next->next;
	tmp = head2->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_tmp;
	first_tmp->next = NULL;
	return ("ra\n");
}

char	*ft_rotate_r(t_stack *head1, t_stack *head2)
{
	ft_rotate_a(head1);
	ft_rotate_b(head2);
	return ("rr\n");
}


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

char	*ft_swap_s(t_stack *head1, t_stack *head2)
{
	if (ft_swap_a(head1) && ft_swap_b(head2))
		return ("ss\n");
	return (NULL);
}

void	ft_sort(t_stack *head1, t_stack *head2)
{
	t_stack	*curr1;
	t_stack	*curr2;

	if (!head2->next)
		ft_push_b(head1, head2);
	curr1 = head1->next;
	while (head1->next)
	{
		if (curr1->num > head2->next)
		{
			curr1 = curr1->next;
			ft_push_b(head1, head2);
		}
		else if (curr1->num < head2->next)
		{
			while (head2->next)
			{
				ft_push_a(head1, head2);
			}
		}
	}
}

void	ft_algo_control(t_stack *head1, t_stack *head2)
{

	while (!ft_check_order(head1, head2))
	{
		ft_sort(head1, head2);
	}
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
		tmp->next = ft_create_node();
		tmp = tmp->next;
		tmp->num = ft_atoi(argv[i]);
		i++;
	}
	return (head1);
}

int	main(int argc, char **argv)
{
	t_stack	*head1;
	t_stack *head2;

	head1 = ft_build_stack(argv);
	head2 = ft_create_node();
	ft_algo_control(head1, head2);
}
