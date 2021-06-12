/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:25:47 by laube             #+#    #+#             */
/*   Updated: 2021/06/10 11:43:55 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	not_in_part(t_stack *head, int head_type, int midp)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = stack_len(head);
	arr = stack_to_arr(head, len);
	while (i < len)
	{
		if (head_type == 1 && arr[i] < midp)
			return (0);
		if (head_type == 2 && arr[i] > midp)
			return (0);
		i++;
	}
	return (1);
}

int	part_midp(t_part *part, t_stack *head, int head_type)
{
	int		*arr;
	int		len;
	t_stack	*curr;
	int		sorted;

	if (part->amt == 0)
	{
		free_part(head);
		return (0);
	}
	len = 0;
	curr = head->next;
	arr = ft_calloc(part->amt, sizeof(int));
	while (len < part->amt && curr)
	{
		arr[len++] = curr->num;
		curr = curr->next;
	}
	sorted = arr_is_sorted(arr, len, head_type);
	arr_quicksort_control(arr, 0, len - 1);
	part->midp = arr[len / 2];
	free(arr);
	arr = NULL;
	return (sorted);
}

void	rev_rotation(t_stack *head, int rot_count, int head_type)
{
	if (head_type == 1)
		while (rot_count-- > 0)
			ft_putstr_fd(ft_reverse_rot_a(head), 1);
	else if (head_type == 2)
		while (rot_count-- > 0)
			ft_putstr_fd(ft_reverse_rot_b(head), 1);
}
