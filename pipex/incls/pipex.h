/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:05:44 by laube             #+#    #+#             */
/*   Updated: 2021/07/20 20:41:45 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include "pipex.h"
# include "error_msg.h"
# include <stdlib.h>
# include <stdio.h>

void	terminate(char *errstr);
char	*bin_path(char **envp, char **cmd);
void	free_table(char ***table);
void	check_access(char *path, int write);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char const *s, int fd);
int		ft_strlen(const char *s);

#endif
