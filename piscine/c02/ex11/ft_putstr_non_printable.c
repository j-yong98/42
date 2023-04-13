/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:18:27 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/16 14:23:11 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char ch)
{
	if (ch >= 32 && ch <= 126)
	{
		return (1);
	}
	return (0);
}

char	to_char(int n)
{
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (n + '0');
}

void	to_hex(int num)
{
	unsigned char	ch;

	write(1, "\\", 1);
	ch = to_char(num / 16);
	write(1, &ch, 1);
	ch = to_char(num % 16);
	write(1, &ch, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				idx;
	unsigned char	ch;

	idx = 0;
	while (*(str + idx))
	{
		ch = *(str + idx);
		if (!is_printable(ch))
			to_hex(ch);
		else
			write(1, &ch, 1);
		idx++;
	}
}
