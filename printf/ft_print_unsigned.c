/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uitoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:58:58 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/22 11:50:23 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
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
	tmp = ft_print_unsigned(num / 10);
	if (tmp < 0 || write(1, &ch, 1) < 0)
		return (-1);
	len += tmp;
	return (len + 1);
}
