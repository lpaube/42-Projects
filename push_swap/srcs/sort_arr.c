/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:23:01 by laube             #+#    #+#             */
/*   Updated: 2021/06/09 16:14:31 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	low_num(t_stack *head)
{
	int	*arr;
	int	len;
	int	i;
	int	low;

	i = 0;
	len = stack_len(head);
	arr = stack_to_arr(head, len);
	low = arr[0];
	while (i < len)
	{
		if (arr[i] < low)
			low = arr[i];
		i++;
	}
	return (low);
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

int	arr_is_sorted(int *arr, int len, int head_type)
{
	int	i;

	i = 0;
	if (len == 1)
	{
		return (1);
	}
	if (head_type == 1)
		while (i < len - 1)
		{
			if (arr[i + 1] < arr[i])
			{
				return (0);
			}
			i++;
		}
	else if (head_type == 2)
		while (i < len - 1)
		{
			if (arr[i + 1] > arr[i])
			{
				return (0);
			}
			i++;
		}
	return (1);
}
