/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroh <sroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:11:41 by sroh              #+#    #+#             */
/*   Updated: 2023/01/15 14:10:09 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(char start, char mid, char end, int col)
{
	int	i;

	i = 1;
	while (i <= col)
	{
		if (i == 1)
		{
			ft_putchar(start);
		}
		else if (i == col)
		{
			ft_putchar(end);
		}
		else
		{
			ft_putchar(mid);
		}
		i++;
	}
}

void	rush(int x, int y)
{
	int	row;
	
	row = 1;
	while (row <= y)
	{
		if (row == 1)
		{
			ft_print('A', 'B', 'C', x);
		}
		else if (row == y)
		{
			ft_print('C', 'B', 'A', x);
		}
		else
		{
			ft_print('B', ' ', 'B', x);
		}
		row++;
		write(1, "\n", 1);
	}
}
