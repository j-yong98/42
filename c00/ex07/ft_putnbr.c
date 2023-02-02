/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:29:27 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/12 21:04:01 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	print_number(int number);
void	process_min_int(int nb);

void	print_number(int number)
{
	char	c;

	if (number == 0)
		return ;
	print_number(number / 10);
	c = number % 10 + '0';
	write(1, &c, 1);
}

void	process_min_int(int nb)
{
	char	c;

	c = '-';
	write(1, &c, 1);
	c = '8';
	nb++;
	nb = -nb;
	print_number(nb / 10);
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == 0)
	{
		c = '0';
		write(1, &c, 1);
		return ;
	}
	if (nb == -2147483648)
	{
		process_min_int(nb);
		return ;
	}
	if (nb < 0)
	{
		c = '-';
		nb = -nb;
		write(1, &c, 1);
	}
	print_number(nb);
}
