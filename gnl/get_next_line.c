/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:09:58 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/31 21:26:48 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buf(char *res, char *buf, int *s, int r)
{
	int	idx;
	int	len;

	idx = find_new_line(buf, s);
	len = ft_strlen(res);
	if (idx == -1)
		idx = r;
	res = ft_expand(res, idx, len);
	if (!res)
		return (NULL);
	ft_strlcat(res, buf, len + idx + 1);
	ft_strlcpy(buf, buf + idx, BUFFER_SIZE + 1, BUFFER_SIZE - idx);
	return (res);
}

char	*read_save(char *buf, int *s)
{
	char	*res;
	int		idx;
	int		len;

	len = ft_strlen(buf);
	if (!len)
		return (NULL);
	res = NULL;
	idx = find_new_line(buf, s);
	if (idx == -1)
		idx = len;
	res = ft_expand(res, idx, 0);
	if (!res)
		return (NULL);
	ft_strlcpy(res, buf, idx + 1, len);
	ft_strlcpy(buf, buf + idx, BUFFER_SIZE + 1, BUFFER_SIZE - idx);
	return (res);
}

int	find_new_line(char *str, int *s)
{
	int	len;
	int	idx;

	len = ft_strlen(str);
	idx = 0;
	while (idx < len)
	{
		if (*(str + idx) == '\n')
		{
			*s = 0;
			return (idx + 1);
		}
		idx++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*res;
	int			r;
	int			s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = 1;
	res = read_save(buf, &s);
	while (s)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r < 0)
		{
			free(res);
			return (NULL);
		}
		buf[r] = 0;
		res = read_buf(res, buf, &s, r);
		if (!res)
			return (NULL);
	}
	return (res);
}
