/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:44:36 by laube             #+#    #+#             */
/*   Updated: 2021/03/21 16:56:41 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// TO REMOVE SPACES FROM INPUT
char	*ft_input(char *arr)
{
	int	index;
	int	size;
	char	*newArr;

	size = 0;
	while (arr[size - 1] != 0)
	{
		size++;
	}
	size = size / 2;
	
	newArr = malloc(size);
	index = 0;
	while (*arr != '\0')
	{
		if (*arr >= '0' && *arr <= '9')
		{
			newArr[index] = *arr;
			index++;
		}
		arr++;
	}
	return (newArr);
}

// TO MEASURE MAX-LENGTH OF A SIDE
int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}
