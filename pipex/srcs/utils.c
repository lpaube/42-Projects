/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:26:31 by laube             #+#    #+#             */
/*   Updated: 2021/07/20 20:40:36 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/pipex.h"

void	check_access(char *path, int write)
{
	if (write == 0)
	{
		if (access(path, F_OK) == -1)
			terminate(ERR_READ);
		if (access(path, R_OK) == -1)
			terminate(ERR_READ);
	}
	else if (write == 1)
	{
		if (access(path, F_OK) != -1)
		{
			if (access(path, W_OK) == -1)
				terminate(ERR_WRITE);
		}
	}
}

void	terminate(char *errstr)
{
	if (errno != 0)
		perror(errstr);
	else
		ft_putstr_fd(errstr, 2);
	exit(0);
}

void	free_table(char ***table)
{
	int	i;

	i = 0;
	while ((*table)[i])
		free((*table)[i++]);
	free(*table);
}

char	*parse_path(char *path, char *cmd)
{
	char	**paths;
	char	*tmp_path;
	char	*tmp_binpath;

	path = ft_strchr(path, '=') + 1;
	paths = ft_split(path, ':');
	while (*paths)
	{
		tmp_path = ft_strjoin(*paths, "/");
		tmp_binpath = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (access(tmp_binpath, F_OK) == 0)
			return (tmp_binpath);
		free(tmp_binpath);
		paths++;
	}
	terminate(ERR_INVALID_BIN);
	return (NULL);
}

char	*bin_path(char **envp, char **cmd)
{
	char	*path;

	while (*envp)
	{
		path = ft_strnstr(*envp, "PATH=", ft_strlen(*envp));
		if (path != NULL)
			return (parse_path(path, cmd[0]));
		envp++;
	}
	return (NULL);
}
