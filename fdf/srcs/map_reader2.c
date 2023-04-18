/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:14:27 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/11 22:21:39 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(char **split)
{
	size_t	len;

	len = 0;
	while (*(split + len))
	{
		free(*(split + len));
		len++;
	}
	free(split);
}

int	*convert_int(char **split, size_t col)
{
	int		*res;
	size_t	idx;

	res = (int *)malloc(sizeof(int) * col);
	if (!res)
		ft_error("Allocation Error");
	idx = 0;
	while (*(split + idx))
	{
		*(res + idx) = ft_atoi(*(split + idx));
		idx++;
	}
	return (res);
}

char	**row_split(char *line)
{
	char	*trim;
	char	**split;

	trim = ft_strtrim(line, "\n");
	split = ft_split(trim, ' ');
	free(line);
	free(trim);
	return (split);
}

size_t	word_cnt(char **split)
{
	size_t	idx;

	idx = 0;
	if (!split)
		ft_error("Allocation Error");
	while (*(split + idx))
		idx++;
	return (idx);
}
