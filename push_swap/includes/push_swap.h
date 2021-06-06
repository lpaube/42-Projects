/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:58:22 by laube             #+#    #+#             */
/*   Updated: 2021/06/06 13:14:47 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct s_part
{
	int				amt;
	int				midp;
	int				sorted;
	struct s_part	*next;
} t_part;

typedef struct s_stack
{
	int				num;
	struct s_part	*part_head;
	struct s_stack	*next;
} t_stack;

t_part	*create_node_part(void);
int	partitioning_b(t_stack *head1, t_stack *head2);
int	partitioning_a(t_stack *head1, t_stack *head2);
int	part_midp(t_part *part, t_stack *head, int head_type);
