/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:14:44 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/29 23:33:55 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mynums.h"

void	print_error(char *str)
{
	int	strlen;

	strlen = len(str);
	write(1, str, strlen);
}

int	get_sign(char *arg)
{
	int	sign;

	sign = 1;
	while (*arg && (*arg == '-' || *arg == '+'))
	{
		if (*arg == '-')
			sign *= -1;
		arg++;
	}
	return (sign);
}

char	*arg_check(char *arg)
{
	int	sign;
	int	len;

	while (*arg && is_space(*arg))
		arg++;
	sign = get_sign(arg);
	len = 0;
	while (*(arg + len))
	{
		if (!(*(arg + len) >= '0' && *(arg + len) <= '9'))
		{
			*(arg + len) = '\0';
			break ;
		}
		len++;
	}
	if (sign == -1)
		*arg = '\0';
	return (arg);
}

void	free_dict(t_mynums *cur)
{
	t_mynums	*addr;

	while (cur)
	{
		addr = cur;
		cur = cur->next;
		free(addr);
	}
}

int	is_validate_key(char *key)
{
	while (*key)
	{
		if (!(*key >= '0' && *key <= '9'))
			return (0);
		key++;
	}
	return (1);
}
