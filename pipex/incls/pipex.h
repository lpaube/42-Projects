/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:05:44 by laube             #+#    #+#             */
/*   Updated: 2021/07/18 19:39:10 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include "../libft/libft.h"
#include "pipex.h"
#include "error_msg.h"

#include <stdio.h>

void	terminate(char *errstr);
char	*bin_path(char **envp, char **cmd);
void	free_table(char ***table);
void	check_access(char *path, int write);

#endif
