/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:49:50 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/28 19:39:02 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	to_int(char *str)
{
	int	res;

	res = 0;
	while (is_digit(*str))
	{
		res *= 10;
		res += (*str) - '0';
		str++;
	}
	return (res);
}

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	if (ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{	
	int	sign_cnt;
	int	res;

	while (is_space(*str))
		str++;
	sign_cnt = 1;
	while (*(str) && !is_digit(*str))
	{
		if (*str != '+' && *str != '-')
			return (0);
		if (*str == '-')
			sign_cnt *= -1;
		str++;
	}
	res = to_int(str);
	res *= sign_cnt;
	return (res);
}
