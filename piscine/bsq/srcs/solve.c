/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:16:57 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 21:15:32 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "info.h"
#include "my_string.h"
#include "error.h"
#include "map_read.h"
#include "find_answer.h"
#include "solve.h"

void	solve(char *filename)
{
	t_info	info;

	if (set_info(&info, filename) == ERROR)
	{
		my_putstr("map error\n");
		return ;
	}
	if (find_square(&info) == ERROR)
	{
		my_putstr("dp malloc error\n");
		return ;
	}
	my_putmap(&info);
	info_free(&info);
	return ;
}

void	info_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->line)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
	return ;
}
