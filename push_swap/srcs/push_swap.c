/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:19 by laube             #+#    #+#             */
/*   Updated: 2021/06/06 09:48:50 by laube            ###   ########.fr       */
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

void	part_midp(t_part *part, t_stack *head)
{
	int	*arr;
	int	len;
	t_stack	*curr;

	len = 0;
	curr = head->next;
	arr = ft_calloc(part->amt, sizeof(int));
	while (len < part->amt && curr)
	{
		arr[len++] = curr->num;
		curr = curr->next;
	}
	arr_quicksort_control(arr, 0, len - 1);
	part->midp = arr[len / 2];
}

void	part_control_a(t_stack *head1, t_stack *head2)
{
	int	*arr;
	int	midp;
	t_part	*curr_part;
	
	curr_part = head2->part_head;
	while (curr_part->next)
		curr_part = curr_part->next;
	while (head1->part_head->next->amt > 2)
	{
		curr_part->next = create_node_part();
		curr_part = curr_part->next;
		midp = head1->part_head->next->midp;
		curr_part->amt = partitioning_a(head1, head2);
		part_midp(curr_part, head2);
	}
	if (head1->next->num > head1->next->next->num)
		printf("%s", ft_swap_a(head1));
}

int	partitioning_a(t_stack *head1, t_stack *head2)
{
	int	i;
	int	counter;
	int	len_og;
	t_part	*curr_part;

	curr_part = head1->part_head->next;
	while (curr_part->next)
		curr_part = curr_part->next;
	counter = 0;
	i = 0;
	len_og = curr_part->amt;
	while (i++ < len_og)
	{
		printf("Head1num: %d | i: %d\n", head1->next->num, i);
		if (head1->next->num < curr_part->midp)
		{
			printf("%s", ft_push_b(head1, head2));
			counter++;
			curr_part->amt--;
		}
		else
		{
			printf("%s", ft_rotate_a(head1));
		}
		ft_print_stacks(head1, head2);
	}
	part_midp(curr_part, head1);
	return (counter);
}

int	partitioning_b(t_stack *head1, t_stack *head2)
{
	t_part	*curr_part;
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	curr_part = head2->part_head->next;
	while (curr_part->next)
		curr_part = curr_part->next;
	if (curr_part->amt <= 2)
	{
		if (curr_part->amt == 2)
		{
			if (head2->next->num < head2->next->next->num)
				ft_swap_b(head2);
			printf("%s", ft_push_a(head1, head2));
			printf("%s", ft_push_a(head1, head2));
			counter += 2;
			curr_part->amt -= 2;
		}
		else if (curr_part->amt == 1)
			printf("%s", ft_push_a(head1, head2));
	}
	while (i++ < curr_part->amt)
	{
	//	printf("MIDP: %d | AMT: %d | i: %d\n", curr_part->midp, curr_part->amt, i);
		if (head2->next->num > curr_part->midp)
		{
			printf("%s", ft_push_a(head1, head2));
			counter++;
			curr_part->amt--;
		}
		else
		{
			printf("%s", ft_rotate_b(head2));
		}
	}
	part_midp(curr_part, head2);
	return (counter);
}
void	free_part(t_stack *head)
{
	t_part	*tmp;

	tmp = head->part_head;
	while (tmp->next)
	{
		if (tmp->next->amt == 0)
		{
			free(tmp->next);
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
}

void	part_control_b(t_stack *head1, t_stack *head2)
{
	t_part	*curr_part;

	curr_part = head1->part_head;
	while (curr_part->next)
		curr_part = curr_part->next;
	while (stack_len(head2))
	{
	/*
		t_stack *tmp = head2->next;
		int i = 0;
		while (tmp)
		{
			printf("NUM: %d | i: %d\n", tmp->num, i);
			i++;
			tmp = tmp->next;
		}
	*/
		curr_part->next = create_node_part();
		curr_part = curr_part->next;
		curr_part->amt = partitioning_b(head1, head2);
		part_midp(curr_part, head1);
		ft_print_stacks(head1, head2);
		free_part(head2);
	}
}

void	ft_algo_control(t_stack *head1, t_stack *head2, int len)
{
	int	*arr;
	int	midpoint;

	part_control_a(head1, head2);
	ft_print_stacks(head1, head2);
	part_control_b(head1, head2);
	ft_print_stacks(head1, head2);
}

t_part	*create_node_part(void)
{
	t_part	*node;

	node = (t_part *)malloc(sizeof(t_part));
	node->amt = 0;
	node->midp = 0;
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
	int	*arr;

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
	init_part1(head1);
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
