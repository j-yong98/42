/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:15:52 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 14:14:34 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "info.h"
#include "my_string.h"
#include "error.h"
#include "map_read.h"

int	set_info(t_info *info, char *filename)
{
	char	*contents;
	char	*cp;
	char	*buf;

	buf = NULL;
	if (read_contents(&contents, filename, &buf) == ERROR)
	{
		free(buf);
		return (ERROR);
	}
	free(buf);
	cp = contents;
	if (read_header(cp, info) == ERROR)
		return (ERROR);
	cp += my_linelen(cp) + 1;
	if (check_map(cp, info) == ERROR)
		return (ERROR);
	alloc_map(info, cp);
	free(contents);
	return (SUCCESS);
}

int	alloc_map(t_info *info, char *cp)
{
	int	linelen;
	int	i;

	info->map = NULL;
	info->map = (char **)malloc((info->line) * sizeof(char *));
	if (info->map == NULL)
		return (ERROR);
	linelen = my_linelen(cp);
	info->linelen = linelen;
	i = 0;
	while (i < info->line)
	{
		info->map[i] = NULL;
		info->map[i] = (char *)malloc(linelen * sizeof(char));
		if (info->map[i] == NULL)
			return (ERROR);
		my_linecpy(info->map[i], cp);
		cp += my_linelen(cp) + 1;
		i++;
	}
	return (SUCCESS);
}

int	read_header(char *header, t_info *info)
{
	int	linelen;

	linelen = my_linelen(header);
	if (linelen < 4)
		return (ERROR);
	info->line = my_linetoi(header, linelen - 3);
	if (info->line <= 0)
		return (ERROR);
	header += linelen - 3;
	if (header[0] == header[1] || header[1] == header[2] \
			|| header[0] == header[2])
		return (ERROR);
	info->empty = header[0];
	info->obstacle = header[1];
	info->full = header[2];
	return (SUCCESS);
}

int	read_contents(char **contents, char *filename, char **buf)
{
	int		len;
	int		fd;

	len = flen(filename, buf);
	if (len == ERROR)
		return (ERROR);
	*contents = (char *)malloc((len + 1) * sizeof(char));
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd == ERROR)
			return (ERROR);
		read(fd, *contents, len);
		(*contents)[len] = '\0';
		close(fd);
	}
	else
		my_strcpy(*contents, *buf);
	return (SUCCESS);
}

int	flen(char *filename, char **buf)
{
	int		fd;
	int		len;

	len = 0;
	if (filename)
	{
		*buf = (char *)malloc(1 * sizeof(char));
		if (*buf == NULL)
			return (ERROR);
		fd = open(filename, O_RDONLY);
		if (fd == ERROR)
			return (ERROR);
		while (read(fd, *buf, 1))
			len++;
		close(fd);
	}
	else
	{
		if (key_input(buf) == ERROR)
			return (ERROR);
		len = my_strlen(*buf);
	}
	return (len);
}
