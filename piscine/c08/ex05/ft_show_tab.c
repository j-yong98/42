/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:29:10 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/27 19:10:02 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putlen(int len)
{
	char	c;

	if (len / 10 == 0)
	{
		c = len % 10 + '0';
		write(1, &c, 1);
		return ;
	}
	ft_putlen(len / 10);
	c = len % 10 + '0';
	write (1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while ((par + idx)->str)
	{
		ft_putstr((par + idx)->str);
		write(1, "\n", 1);
		ft_putlen((par + idx)->size);
		write(1, "\n", 1);
		ft_putstr((par + idx)->copy);
		write(1, "\n", 1);
		idx++;
	}
}
