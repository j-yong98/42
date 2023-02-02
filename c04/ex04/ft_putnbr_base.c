/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:51:19 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/24 23:28:02 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_validate(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_number(unsigned int number, int len, char *base)
{
	char	ch;

	if (number / len == 0)
	{
		write(1, &base[number % len], 1);
		return ;
	}
	print_number(number / len, len, base);
	ch = base[number % len];
	write(1, &ch, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	unsigned int	len;

	len = 0;
	while (*(base + len))
	{
		len++;
	}
	if (len < 2)
		return ;
	if (!is_validate(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = -nbr;
	}
	else
		num = nbr;
	print_number(num, len, base);
}
