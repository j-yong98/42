/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:06:32 by jooypark          #+#    #+#             */
/*   Updated: 2023/01/29 22:10:04 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mynums.h"

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	if (ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

void	pos_hundred(char *num, t_mynums *dict)
{
	char	digit[4];

	digit[0] = num[0];
	digit[1] = '\0';
	if (check_key_exist(num, dict) == 1 && len(num) == 3)
	{
		print_key(digit, dict);
		write(1, " ", 1);
		print_key(num, dict);
		return ;
	}
	if (print_key(num, dict) == 1)
		return ;
	if (num[0] != '0' && len(num) == 3)
	{
		print_key(digit, dict);
		write(1, " ", 1);
		print_key("100", dict);
		if (num[1] != '0' || num[2] != '0')
			write(1, " ", 1);
	}
	pos_ten(num, dict);
}

void	pos_ten(char *num, t_mynums *dict)
{
	char	digit[4];

	if (len(num) == 3)
		num++;
	if (print_key(num, dict) == 1 && len(num) == 2)
		return ;
	if (num[0] != '0' && len(num) == 2)
	{
		digit[0] = num[0];
		digit[1] = '0';
		digit[2] = '\0';
		print_key(digit, dict);
		write(1, "-", 1);
	}
	pos_one(num, dict);
}

void	pos_one(char *num, t_mynums *dict)
{
	if (len(num) == 2)
		num++;
	if (num[0] != '0' && len(num) == 1)
		print_key(num, dict);
}
