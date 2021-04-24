/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:51:46 by laube             #+#    #+#             */
/*   Updated: 2021/03/21 18:15:07 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/* INPUT.C */
int		ft_strlen(char *str);
char	*ft_input(char *arr);

/* TABLE.C */
char	**ft_create_table(int x);
char	**ft_zero_output(char **table0, int len);
void	ft_output(char **table, int len);
char	**ft_table_main(int len);


/* SOLVER.C */
int	ft_solver_main(char **table, int len, char *input);
int	ft_solver(char **table, int row, int col, char *input, char curr);
int	ft_seen_row(char *arr, char first, char second, int max, char curr);
int	ft_row_repeat(char **table, int row, int col, char curr);
int		ft_seen_col(char **table, char first, char second, int max, int col);


int	main(int argc, char **argv)
{
	char	*input;
	char	**table;
	int	len;

	input = ft_input(argv[1]);
	len = ft_strlen(input);
	table = ft_table_main(ft_strlen(input));

	ft_solver_main(table, 4, input);
	ft_output(table, len / 4);
}
