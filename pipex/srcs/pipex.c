/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:44:58 by laube             #+#    #+#             */
/*   Updated: 2021/07/20 21:13:14 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/pipex.h"

void	pipe_write(char **argv, char **envp, int *fd)
{
	int		input_fd;
	char	**cmd;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	check_access(argv[0], 0);
	input_fd = open(argv[0], O_RDONLY);
	if (input_fd == -1)
		terminate(ERR_OPEN);
	dup2(input_fd, 0);
	cmd = ft_split(argv[1], ' ');
	if (execve(bin_path(envp, cmd), cmd, envp) == -1)
	{
		free_table(&cmd);
		terminate(ERR_EXEC);
	}
}

void	pipe_read(char **argv, char **envp, int *fd)
{
	int		output_fd;
	char	**cmd;

	wait(0);
	check_access(argv[1], 1);
	output_fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
		terminate(ERR_OPEN);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(output_fd, 1);
	cmd = ft_split(argv[0], ' ');
	if (execve(bin_path(envp, cmd), cmd, envp) == -1)
	{
		free_table(&cmd);
		terminate(ERR_EXEC);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;

	errno = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			terminate("pipe");
		pid1 = fork();
		if (pid1 == 0)
			pipe_write(&argv[1], envp, fd);
		else if (pid1 > 0)
			pipe_read(&argv[3], envp, fd);
		else if (pid1 < 0)
			terminate("fork");
	}
	else
		terminate("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
}
