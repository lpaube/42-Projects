/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:58:22 by laube             #+#    #+#             */
/*   Updated: 2021/06/10 22:19:58 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_part
{
	int				amt;
	int				midp;
	int				sorted;
	struct s_part	*next;
}	t_part;

typedef struct s_stack
{
	int				num;
	struct s_part	*part_head;
	struct s_stack	*next;
}	t_stack;

t_part	*create_node_part(void);
int		partitioning_b(t_stack *head1, t_stack *head2);
int		partitioning_a(t_stack *head1, t_stack *head2);
int		part_midp(t_part *part, t_stack *head, int head_type);
void	solve_3(t_stack *head1);
void	solve_5(t_stack *head1, t_stack *head2);
int		partitioning_a(t_stack *head1, t_stack *head2);
void	part_control_a(t_stack *head1, t_stack *head2);
int		partitioning_b(t_stack *head1, t_stack *head2);
void	part_control_b(t_stack *head1, t_stack *head2);
char	*ft_push_a(t_stack *head1, t_stack *head2);
char	*ft_push_b(t_stack *head1, t_stack *head2);
char	*ft_swap_a(t_stack *head1);
char	*ft_swap_b(t_stack *head2);
char	*ft_reverse_rot_a(t_stack *head1);
char	*ft_reverse_rot_b(t_stack *head2);
char	*ft_rotate_a(t_stack *head1);
char	*ft_rotate_b(t_stack *head2);
t_part	*create_node_part(void);
t_stack	*ft_create_node(void);
void	init_part1(t_stack *head1);
t_stack	*ft_build_stack(char **argv);
int		*stack_to_arr(t_stack *head, int len);
int		arr_quicksort(int *arr, int low, int high);
void	arr_quicksort_control(int *arr, int low, int high);
int		arr_is_sorted(int *arr, int len, int head_type);
void	free_part(t_stack *head);
int		not_in_part(t_stack *head, int head_type, int midp);
int		part_midp(t_part *part, t_stack *head, int head_type);
void	rev_rotation(t_stack *head, int rot_count, int head_type);
int		stack_len(t_stack *head);
int		ft_check_order(t_stack *head1, t_stack *head2);
int		last_num(t_stack *head);
int		has_unsorted(t_stack *head);
int		low_num(t_stack *head);
void	amt_is_2(t_stack *head1, t_part *tmp1);
int		sub_a(t_stack *h1, t_stack *h2, t_part *curr_part, int *rot_count);
void	ft_print_stacks(t_stack *head1, t_stack *head2);
int		high_num(t_stack *head);
int		check_errors(int argc, char **argv);

#endif
