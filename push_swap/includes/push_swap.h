/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:58:22 by laube             #+#    #+#             */
/*   Updated: 2021/06/04 19:01:30 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct s_part
{
	int				amt;
	struct s_part	*next;
} t_part;

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_part	*part_head;
} t_stack;

t_part	*create_node_part(void);
