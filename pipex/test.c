/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:36:26 by laube             #+#    #+#             */
/*   Updated: 2021/07/06 15:44:04 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int	main(void)
{
	int		fd[2];
	pid_t	childpid;

	pipe(fd);

	if ((childpid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
}
