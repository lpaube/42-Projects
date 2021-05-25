/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:19 by laube             #+#    #+#             */
/*   Updated: 2021/05/25 18:02:11 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_build_stack(char **argv, int *stack1)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		stack1[i] = ft_atoi(argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	stack1[argc - 1];
	int	*stack2[argc - 1];

	ft_build_stack(argv, stack1);

	
}
