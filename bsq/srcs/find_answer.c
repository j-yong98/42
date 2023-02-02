/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_answer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:40:15 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 21:43:44 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "square.h"
#include "error.h"
#include "find_answer2.h"
#include "find_answer.h"

int	find_square(t_info *info)
{
	int			**dp;
	t_square	sq;

	dp = dp_init(info);
	if (dp == (void *)0)
		return (ERROR);
	side_init(info, dp);
	square_init(&sq);
	set_dp(info, dp);
	find_max_scale(dp, &sq, info->line, info->linelen);
	dp_free(info, dp);
	draw_sq(info, &sq);
	return (SUCCESS);
}

void	set_dp(t_info *info, int **dp)
{
	int	i;
	int	j;
	int	min;

	min = 2147483647;
	i = 1;
	while (i < info->line)
	{
		j = 1;
		while (j < info->linelen)
		{
			if (info->map[i][j] != info->obstacle)
			{
				min = get_min_value(dp, i, j) + 1;
				if (min > dp[i][j])
					dp[i][j] = min;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	get_min_value(int **dp, int i, int j)
{
	int	res;

	if (dp[i][j - 1] < dp[i - 1][j - 1])
		res = dp[i][j - 1];
	else
		res = dp[i - 1][j - 1];
	if (res > dp[i - 1][j])
		res = dp[i - 1][j];
	return (res);
}

void	find_max_scale(int **dp, t_square *sq, int r, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			if (sq->scale < dp[i][j])
			{
				sq->x = i;
				sq->y = j;
				sq->scale = dp[i][j];
			}
			j++;
		}
		i++;
	}
	return ;
}

void	draw_sq(t_info *info, t_square *sq)
{
	int	i;
	int	j;

	i = (sq->x - sq->scale) + 1;
	while (i <= sq->x)
	{
		j = (sq->y - sq->scale) + 1;
		while (j <= sq->y)
		{
			info->map[i][j] = info->full;
			j++;
		}
		i++;
	}
	return ;
}
