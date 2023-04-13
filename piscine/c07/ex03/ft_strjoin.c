/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:01:40 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/25 20:04:15 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_total_len(char **str, int size)
{
	int	len;
	int	idx;
	int	w_idx;

	len = 0;
	idx = 0;
	w_idx = 0;
	while (idx < size)
	{
		while (*(*(str + idx) + w_idx))
		{
			len++;
			w_idx++;
		}
		idx++;
		w_idx = 0;
	}
	return (len);
}

int	get_len(char *sep)
{
	int	len;

	len = 0;
	while (*sep)
	{
		sep++;
		len++;
	}
	return (len);
}

char	*string_join(char *res, char **str, int size, char *sep)
{
	int		idx;
	int		c_idx;
	int		r_idx;

	idx = 0;
	r_idx = 0;
	while (idx < size)
	{
		c_idx = 0;
		while (*(*(str + idx) + c_idx))
			*(res + r_idx++) = *(*(str + idx) + c_idx++);
		c_idx = 0;
		while (idx != size - 1 && *(sep + c_idx))
			*(res + r_idx++) = *(sep + c_idx++);
		idx++;
	}
	*(res + r_idx) = 0;
	return (res);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*res;
	int		total_len;

	if (size <= 0)
		return (malloc(0));
	total_len = (get_total_len(str, size) + ((size - 1) * get_len(sep))) + 1;
	res = (char *)malloc(sizeof(char) * total_len);
	return (string_join(res, str, size, sep));
}
