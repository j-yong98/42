/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:14:15 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/23 17:30:54 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char c)
{
	if (c == ' ' || c == '\n' || c == '\r')
		return (1);
	if (c == '\f' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	ans;
	int				sign;

	sign = 1;
	ans = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ans = ans * 10 + (*str - '0');
		str++;
	}
	return (ans * sign);
}
