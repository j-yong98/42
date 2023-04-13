/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:24:43 by jelee2            #+#    #+#             */
/*   Updated: 2023/01/31 23:14:55 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "my_string.h"
#include "error.h"

int	check_map(char *map, t_info *info)
{
	int		linelen;
	int		linecnt;
	int		nl_cnt;

	init_check_map(map, &linelen, &linecnt, &nl_cnt);
	if (linelen == 0)
		return (ERROR);
	while (*map != '\0')
	{
		if (*map == '\n')
		{
			if (linecnt != linelen)
				return (ERROR);
			mp_newline(&linecnt, &nl_cnt);
		}
		else if (!mp_in_head(*map, info))
			return (ERROR);
		else
			linecnt++;
		map++;
	}
	if (nl_cnt != info->line)
		return (ERROR);
	return (SUCCESS);
}

void	init_check_map(char *map, int *linelen, int *linecnt, int *nl_cnt)
{
	*linelen = my_linelen(map);
	*linecnt = 0;
	*nl_cnt = 0;
	return ;
}

void	mp_newline(int *linecnt, int *nl_cnt)
{
	*linecnt = 0;
	(*nl_cnt)++;
	return ;
}

int	mp_in_head(char c, t_info *info)
{
	if (c == info->empty)
		return (1);
	else if (c == info->obstacle)
		return (1);
	else
		return (0);
}
