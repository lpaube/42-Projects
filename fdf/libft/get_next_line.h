/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:50:55 by laube             #+#    #+#             */
/*   Updated: 2021/06/15 17:01:28 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		gnl_strlen(const char *s);
char	*gnl_strjoin(char **s1, char *s2);
void	*gnl_calloc(int count, int size);
char	*gnl_strchr(const char *s, int c);
int		gnl_free_it(char **str, int bytes);

#endif
