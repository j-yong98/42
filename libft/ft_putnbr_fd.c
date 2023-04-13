/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:29:44 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/22 17:02:56 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rec_write(unsigned int n, int fd)
{
	char	c;

	c = '0';
	if (n == 0)
	{
		write(fd, &c, 1);
		return ;
	}
	c += n % 10;
	if (n / 10 == 0)
	{
		write(fd, &c, 1);
		return ;
	}
	rec_write(n / 10, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	tmp = n;
	if (n < 0 && tmp > 0)
	{
		write(fd, "-", 1);
		tmp = -n;
	}
	rec_write(tmp, fd);
}
