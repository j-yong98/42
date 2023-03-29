/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:17:33 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/31 11:53:20 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c11.h"

int	operate(int s1, int s2, char *op)
{
	int	(*f[5])(int, int);

	f[0] = add;
	f[1] = sub;
	f[2] = div;
	f[3] = mul;
	f[4] = mod;
	if (*op == '+')
		return (add(s1, s2));
	if (*op == '-')
		return (sub(s1, s2));
	if (*op == '/')
		return (div(s1, s2));
	if (*op == '%')
		return (mod(s1, s2));
	if (*op == '*')
		return (mul(s1, s2));
	return (0);
}

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int	op_check(char *op)
{
	if (ft_len(op) > 1)
		return (0);
	if (*op == '+' || *op == '-')
		return (1);
	if (*op == '/' || *op == '%' || *op == '*')
		return (1);
	return (0);
}

void	calc(char *s1, char *s2, char *op)
{
	int		n1;
	int		n2;

	if (!op_check(op))
	{
		ft_print(0);
		return ;
	}
	n1 = ft_atoi(s1);
	n2 = ft_atoi(s2);
	if (n2 == 0 && (*op == '/' || *op == '%'))
	{
		if (*op == '/')
			write(2, "Stop : division by zero\n", 24);
		else if (*op == '%')
			write(2, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_print(operate(n1, n2, op));
}
