/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:44:37 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/19 09:42:40 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(unsigned int nb)
{
	char	c;

	if (nb == 0)
		return ;
	c = nb % 10 + '0';
	print_number(nb / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	u_nb;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		u_nb = -nb;
	}
	else
		u_nb = nb;
	print_number(u_nb);
}
