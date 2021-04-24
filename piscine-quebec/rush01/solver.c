/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:43:24 by laube             #+#    #+#             */
/*   Updated: 2021/03/21 18:15:03 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_row_repeat(char **table, int row, int col, char curr);
int	ft_solver(char **table, int row, int col, char *input);
int	ft_seen_row(char *arr, char first, char second, int max, char **table, char curr);
int		ft_seen_col(char **table, char first, char second, int max, int col, char curr);
void	ft_output(char **table, int len);

// MAIN OF SOLVER
int	ft_solver_main(char **table, int len, char *input)
{
	ft_solver(table, 0, 0, input);
	return (0);
}

// RECURSIVE SOLVING FUNCTION
int	ft_solver(char **table, int row, int col, char *input)
{
	int	i;
	// If we have reached more than last cell, we are done
	if (row == 3 && col == 4)
	{
		return (1);
	}

	// If col at end, move to next row
	if (col == 4)
	{
			col = 0;
			row++;
	}
	
	// If current position already has number, call same func for next cell
/*
	if (table[row][col] > '0')
		return ft_solver(table, row, col, input);
		*/

	i = 1;
	while (i <= 4)
	{
		// Checks if curr num is safe. Will need to add more conditions
		if (ft_row_repeat(table, row, col, i + '0')) 
		{
			table[row][col] = i + '0';
			if (ft_seen_row(table[row], input[8 + row], input[12 + row], 4, table, i + '0') && ft_seen_col(table, input[0 + col], input[4 + col], 4, col, i + '0'))
			{
				if (ft_solver(table, row, col + 1, input))
					return (1);
			//	table[row][col] = '0';
			}
		}
		// Removing the assigned num, since solver(col + 1) did not work
		table[row][col] = '0';
		i++;
	}
	return (0);
}

// SEE IF THE ROW/COL NUMBERS REPEAT
int	ft_row_repeat(char **table, int row, int col, char curr)
{
	int	i;

	i = 0;
	while (table[row][i] != '\0')
	{
		if (table[row][i] == table[row][col] && curr != '0')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	// will need to update to match dynamic size
	while (i < 4)
	{
		if (table[i][col] == table[row][col])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// DOES IT MEET THE INPUT ON THE ROW?
int		ft_seen_row(char *arr, char first, char second, int max, char **table, char curr)
{
	int	index;
	int	counter;
	char	holder;

	index = 0;
	counter = 0;
	holder = '0';
	while (index < max)
	{
		if (arr[index] > holder)
		{
			counter++;
			holder = arr[index];
		}
		index++;
	}
	if (counter > first - '0')
	{
		return (0);
	}
	holder = '0';
	counter = 0;
	while (index > -1)
	{
		if (arr[index] > holder)
		{
			counter++;
			holder = arr[index];
		}
		index--;
	}
	if (counter > second - '0')
	{
		return (0);
	}
	return (1);
}

int		ft_seen_col(char **table, char first, char second, int max, int col, char curr)
{
	int	index;
	int	counter;
	char	holder;

	index = 0;
	counter = 0;
	holder = '0';
	while (index < max)
	{
		if (table[index][col] > holder)
		{
			counter++;
			holder = table[index][col];
		}
		index++;
	}
	if (counter > first - '0')
	{
		return (0);
	}
	holder = '0';
	counter = 0;
	while (--index > -1)
	{
		if (table[index][col] > holder)
		{
			counter++;
			holder = table[index][col];
		}
	}
	if (counter > second - '0')
	{
		return (0);
	}
	return (1);
}
