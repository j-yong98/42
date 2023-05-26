/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:30:48 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/21 20:48:23 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putch(int c)
{
	return (write(1, &c, 1));
}

int	ft_puts(char *str)
{
	int	len;

	if (!str)
		return (ft_puts("(null)"));
	len = 0;
	while (*str)
	{
		if (write(1, str, 1) < 0)
			return (-1);
		len++;
		str++;
	}
	return (len);
}
