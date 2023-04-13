/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:06:47 by jooypark          #+#    #+#             */
/*   Updated: 2023/01/29 22:51:36 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mynums.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*make_num_front(char *num, int num_len)
{
	char	*num1;
	int		i;

	num1 = (char *)malloc(sizeof(char) * 10);
	i = 0;
	if (num_len % 3 == 0)
	{
		while (i < 3)
		{
			num1[i] = num[i];
			i++;
		}
		num1[i] = '\0';
	}
	else
	{
		while (i < num_len % 3)
		{
			num1[i] = num[i];
			i++;
		}
		num1[i] = '\0';
	}
	return (num1);
}

int	check_all_zero(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

char	*parse_num(char *num, int num_len, t_mynums *dict)
{
	char	*str;
	int		num_flen;
	int		i;

	str = make_num_front(num, num_len);
	pos_hundred(str, dict);
	num_flen = len(make_num_front(num, num_len));
	i = 1;
	if (str[0] != '0' || str[1] != '0' || str[2] != '0')
	{
		str[0] = '1';
		while (i < num_len - num_flen + 1)
		{
			str[i] = '0';
			i++;
		}
		str[i] = '\0';
		write(1, " ", 1);
		print_key(str, dict);
		if (check_all_zero(num + num_flen) == 1)
			write(1, " ", 1);
	}
	num += num_flen;
	return (num);
}

void	print_num(char *num, t_mynums *dict)
{
	int		num_len;

	num_len = 0;
	while (num[num_len])
		num_len++;
	if (num_len < 4)
	{
		pos_hundred(num, dict);
		return ;
	}
	else
		num = parse_num(num, num_len, dict);
	print_num(num, dict);
}
