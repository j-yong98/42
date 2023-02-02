/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:39:43 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 16:21:37 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "info.h"
#include "error.h"
#include "my_string.h"
#include "map_read2.h"

int	key_input(char **buf)
{
	unsigned long long	i;
	int					lcnt;
	int					headlen;
	int					line;
	char				head[STDIN_MAX + 1];

	headlen = init_head(head);
	if (headlen < 4)
		return (ERROR);
	line = my_linetoi(head, headlen - 3);
	if (line <= 0)
		return (ERROR);
	*buf = (char *)malloc(STDIN_MAX * line);
	if (*buf == NULL)
		return (ERROR);
	init_buf(*buf, line);
	my_strcpy(*buf, head);
	i = my_strlen(head);
	lcnt = 0;
	while (lcnt < line)
	{
		i += read(0, &(*buf)[i], STDIN_MAX);
		lcnt++;
	}
	return (SUCCESS);
}

int	init_head(char *head)
{
	int	i;

	i = 0;
	while (i < STDIN_MAX + 1)
		head[i++] = '\0';
	read(0, head, STDIN_MAX);
	return (my_linelen(head));
}

void	init_buf(char *buf, int line)
{
	int	i;

	i = 0;
	while (i < line * STDIN_MAX)
		buf[i++] = '\0';
	return ;
}
