/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:01:23 by laube             #+#    #+#             */
/*   Updated: 2021/03/23 19:16:45 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_join(int size, char **strs, char *sep, char *newstr);
int		ft_strlen(int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*newstr;

	newstr = malloc((ft_strlen(size, strs, sep) + 1) * sizeof(char));
	if (newstr == 0)
		return (0);
	ft_join(size, strs, sep, newstr);
	return (newstr);
}

int	ft_strlen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			counter++;
		i++;
	}
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (sep[j++])
			counter++;
		i++;
	}
	return (counter);
}

void	ft_join(int size, char **strs, char *sep, char *newstr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			*newstr = strs[i][j++];
			newstr++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			*newstr = sep[j++];
			newstr++;
		}
		i++;
	}
	*newstr = 0;
}
