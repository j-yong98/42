/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:55:13 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/22 11:52:29 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnb(unsigned int num)
{
	char	ch;
	int		len;
	int		tmp;

	len = 0;
	ch = num % 10 + '0';
	if (num / 10 == 0)
	{
		if (write(1, &ch, 1) < 0)
			return (-1);
		return (len + 1);
	}
	tmp = ft_putnb(num / 10);
	if (tmp < 0 || write(1, &ch, 1) < 0)
		return (-1);
	len += tmp;
	return (len + 1);
}

int	ft_print_decimal(int num)
{
	unsigned int	tmp;
	int				len;

	len = 0;
	tmp = num;
	if (num < 0)
	{
		len = write(1, "-", 1);
		tmp = -num;
	}
	if (len < 0)
		return (-1);
	len += ft_putnb(tmp);
	if (len < 0)
		return (-1);
	return (len);
}
