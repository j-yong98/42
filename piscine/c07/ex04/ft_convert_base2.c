/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:15:52 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/25 11:06:19 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_idx(char c, char *base)
{
	int	idx;

	idx = 0;
	while (*(base + idx))
	{
		if (c == *(base + idx))
			return (idx);
		idx++;
	}
	return (-1);
}

int	to_int(char *str, char *base_from, int f_len)
{
	int	res;
	int	idx;

	res = 0;
	while (*str)
	{
		idx = get_idx(*str, base_from);
		if (idx == -1)
			break ;
		res = (res * f_len) + idx;
		str++;
	}
	return (res);
}

int	recur_save_num(int num, char *base_to, int t_len, char *str)
{
	int	idx;

	idx = 0;
	if (num / t_len == 0)
	{
		*(str + idx) = base_to[num % t_len];
		return (1);
	}
	idx += recur_save_num(num / t_len, base_to, t_len, str);
	*(str + idx) = base_to[num % t_len];
	return (idx + 1);
}

int	get_num_len(int num, int t_len)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= t_len;
	}
	return (len);
}

char	*convert_base_to(int num, char *base_to, int t_len, int sign)
{
	char	*str;
	int		idx;

	str = (char *)malloc(sizeof(char) * get_num_len(num, t_len) + 1);
	idx = 0;
	if (num > 0 && sign < 0)
		*(str + idx++) = '-';
	idx = recur_save_num(num, base_to, t_len, str + idx);
	if (sign == -1)
		idx++;
	*(str + idx) = 0;
	return (str);
}
