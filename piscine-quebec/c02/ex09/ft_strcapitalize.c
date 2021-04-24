/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:49:42 by laube             #+#    #+#             */
/*   Updated: 2021/03/15 13:58:29 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isNum(char c);
int	ft_isLower(char c);
int	ft_isUpper(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	upperState;

	upperState = 1;
	i = 0;
	while (1)
	{
		if (ft_isNum(str[i]) || ft_isUpper(str[i]) || ft_isLower(str[i]))
		{
			if (ft_isLower(str[i]) && upperState == 1)
				str[i] = str[i] - 32;
			else if (ft_isUpper(str[i]) && upperState == 0)
				str[i] = str[i] + 32;
			upperState = 0;
		}
		else
		{
			if (str[i] == '\0')
				return (str);
			upperState = 1;
		}
		i++;
	}
}

int	ft_isNum(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_isUpper(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_isLower(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
