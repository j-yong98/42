/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:11:28 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/31 21:14:42 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strllen(char *str);
size_t	ft_strllcpy(char *dst, char *src, size_t len, size_t s_len);
size_t	ft_strllcat(char *dst, char *src, size_t len);
void	*ft_expand(void *ptr, size_t size, int len);
int		find_new_line(char *str, int *s);
char	*read_save(char *buf, int *s);
char	*read_buf(char *res, char *buf, int *s, int r);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif
