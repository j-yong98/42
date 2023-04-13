/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:22:47 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/22 12:00:58 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long p)
{
	int	len;
	int	tmp;

	len = 0;
	if (p / 16 == 0)
	{
		if (write(1, &"0123456789abcdef"[p % 16], 1) < 0)
			return (-1);
		return (len + 1);
	}
	tmp = ft_print_ptr(p / 16);
	if (tmp < 0 || write(1, &"0123456789abcdef"[p % 16], 1) < 0)
		return (-1);
	len += tmp;
	return (len + 1);
}
