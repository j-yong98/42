/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:59:29 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/20 19:19:58 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	base_check(char *base)
{
	int	len;
	int	j;

	len = 0;
	while (*(base + len))
	{
		if (*(base + len) == '-' || *(base + len) == '+')
			return (0);
		if (is_space(*(base + len)))
			return (0);
		j = len + 1;
		while (*(base + j))
		{
			if (*(base + len) == *(base + j))
				return (0);
			j++;
		}
		len++;
	}
	return (len);
}

int	get_idx(char c, char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_res(char *str, char *base, int b_len, int sign_cnt)
{
	long long	res;
	int			idx;

	res = 0;
	while (*str)
	{
		idx = get_idx(*str, base);
		if (idx == -1)
			return (res);
		res = (res * b_len) + idx;
		str++;
	}
	if (res < -2147483648 || res > 2147483647)
		return (0);
	res *= sign_cnt;
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b_len;
	int	res;
	int	sign_cnt;

	b_len = base_check(base);
	if (b_len < 2)
		return (0);
	while (*str && is_space(*str))
		str++;
	sign_cnt = 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign_cnt *= -1;
		str++;
	}
	res = get_res(str, base, b_len, sign_cnt);
	return (res);
}
