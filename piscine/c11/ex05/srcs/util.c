/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:32:51 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/31 11:53:27 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c11.h"

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
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && is_space(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

void	print_num(unsigned int tmp)
{
	char	ch;

	if (tmp / 10 == 0)
	{
		ch = tmp % 10 + '0';
		write(1, &ch, 1);
		return ;
	}
	print_num(tmp / 10);
	ch = tmp % 10 + '0';
	write(1, &ch, 1);
}

void	ft_print(int num)
{
	unsigned int	tmp;

	if (num < 0)
	{
		write(1, "-", 1);
		tmp = -num;
	}
	else
		tmp = (unsigned int) num;
	print_num(tmp);
	write(1, "\n", 1);
}
