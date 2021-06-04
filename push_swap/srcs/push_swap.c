/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:19 by laube             #+#    #+#             */
/*   Updated: 2021/06/04 19:04:16 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	head2->next = head2->next->next;
	tmp = head2->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_tmp;
	first_tmp->next = NULL;
	return ("rb\n");
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
	
}

int	*stack_to_arr(t_stack *head, int len)
{
	int		*arr;
	int		i;
	t_stack	*curr;

	arr = ft_calloc(len, sizeof(int));
	curr = head->next;
	i = 0;
	while (i < len && curr)
	{
		arr[i++] = curr->num;
		curr = curr->next;
	}
	return (arr);
}

int	arr_quicksort(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			ft_swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

void	arr_quicksort_control(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = arr_quicksort(arr, low, high);
		arr_quicksort_control(arr, low, pi - 1);
		arr_quicksort_control(arr, pi + 1, high);
	}
}

int	partitioning(int len, int midpoint, t_stack *head1, t_stack *head2)
{
	t_stack	*curr1;
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	printf("MID: %d\n", midpoint);
	while (i++ < len)
	{
		if (head1->next->num < midpoint)
		{
			printf("%s", ft_push_b(head1, head2));
			counter++;
		}
		else
		{
			printf("%s", ft_rotate_a(head1));
		}
	}
	return (counter);
}

void	recurse_partition(t_stack *head1, t_stack *head2)
{
	int	*arr;
	int	midp;
	t_part	*curr_part;

	curr_part = head1->part_head;
	while (stack_len(head1) > 2)
	{
		curr_part->next = create_node_part();
		curr_part = curr_part->next;
		arr = stack_to_arr(head1, stack_len(head1));
		arr_quicksort_control(arr, 0, stack_len(head1) - 1);
		midp = arr[stack_len(head1) / 2];
		curr_part->amt = partitioning(stack_len(head1), midp, head1, head2);
	}
}

void	ft_algo_control(t_stack *head1, t_stack *head2, int len)
{
	int	*arr;
	int	midpoint;

	recurse_partition(head1, head2);

	ft_print_stacks(head1, head2);

	t_part *tmp = head1->part_head->next;
	while (tmp)
	{
		printf("PART NUM: %d\n", tmp->amt);
		tmp = tmp->next;
	}
}

t_part	*create_node_part(void)
{
	t_part	*node;

	node = (t_part *)malloc(sizeof(t_part));
	node->amt = 0;
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

t_stack	*ft_build_stack(char **argv)
{
	t_stack	*head1;
	t_stack	*tmp;
	int		i;

	i = 1;
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
	return (head1);
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
