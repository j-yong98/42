/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_answer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:16 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 21:43:09 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "info.h"
#include "square.h"
#include "find_answer2.h"

int	**dp_init(t_info *info)
{
	int	**dp;
	int	i;
	int	j;

	dp = (int **)malloc(info->line * sizeof(int *));
	if (dp == NULL)
		return (NULL);
	i = 0;
	while (i < info->line)
	{
		dp[i] = (int *)malloc(info->linelen * sizeof(int));
		if (dp[i] == NULL)
			return (NULL);
		j = 0;
		while (j < info->linelen)
		{
			dp[i][j] = 0;
			j++;
		}
		i++;
	}
	return (dp);
}

void	dp_free(t_info *info, int **dp)
{
	int	i;

	i = 0;
	while (i < info->line)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
	return ;
}

void	side_init(t_info *info, int **dp)
{
	int	i;

	i = 0;
	while (i < info->line)
	{
		if (info->map[i][0] != info->obstacle)
			dp[i][0] = 1;
		i++;
	}
	i = 0;
	while (i < info->linelen)
	{
		if (info->map[0][i] != info->obstacle)
			dp[0][i] = 1;
		i++;
	}
}

void	square_init(t_square *sq)
{
	sq->x = -1;
	sq->y = -1;
	sq->scale = -1;
}
