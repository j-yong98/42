/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:37:35 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/28 20:53:32 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;
	int		tmp;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			tmp = conversion(*++format, ap);
		else
			tmp = ft_putch(*format);
		if (tmp < 0)
			return (-1);
		cnt += tmp;
		format++;
	}
	va_end(ap);
	return (cnt);
}
