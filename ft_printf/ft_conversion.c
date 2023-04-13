/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:52:35 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/23 10:45:39 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char type, va_list ptr)
{
	if (type == 'c')
		return (ft_putch(va_arg(ptr, int)));
	if (type == 's')
		return (ft_puts(va_arg(ptr, char *)));
	if (type == 'p')
	{
		if (write(1, "0x", 2) < 0)
			return (-1);
		return (ft_print_ptr((unsigned long long)va_arg(ptr, void *)) + 2);
	}
	if (type == 'd' || type == 'i')
		return (ft_print_decimal(va_arg(ptr, int)));
	if (type == 'u')
		return (ft_print_unsigned(va_arg(ptr, unsigned int)));
	if (type == 'x')
		return (ft_print_hex(va_arg(ptr, unsigned int), 0));
	if (type == 'X')
		return (ft_print_hex(va_arg(ptr, unsigned int), 1));
	if (type == '%')
		return (ft_putch('%'));
	return (-1);
}
