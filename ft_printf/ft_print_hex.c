/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:14:15 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/22 14:03:59 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_char(int classify)
{
	if (!classify)
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

int	ft_rec_print(unsigned int num, char *hex)
{
	int	tmp;
	int	len;

	len = 0;
	if (num / 16 == 0)
	{
		if (write(1, &hex[num % 16], 1) < 0)
			return (-1);
		return (len + 1);
	}
	tmp = ft_rec_print(num / 16, hex);
	if (tmp < 0 || write(1, &hex[num % 16], 1) < 0)
		return (-1);
	len += tmp;
	return (len + 1);
}

int	ft_print_hex(unsigned int num, int classify)
{
	char	*hex;

	hex = hex_char(classify);
	return (ft_rec_print(num, hex));
}
