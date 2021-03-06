/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:50:55 by laube             #+#    #+#             */
/*   Updated: 2021/05/19 11:35:28 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
char	*ft_strjoin(char **s1, char *s2);
void	*ft_calloc(int count, int size);
char	*ft_strchr(const char *s, int c);
int		free_it(char **str, int bytes);

#endif
