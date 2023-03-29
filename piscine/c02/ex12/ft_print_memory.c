/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:47:22 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/18 22:57:50 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_memory(unsigned long long addr)
{
	char	ch[16];
	int		idx;

	idx = 0;
	while (idx++ < 16)
	{
		ch[idx] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	while (--idx > 0)
	{
		write(1, &ch[idx], 1);
	}
	write(1, ":", 1);
}

void	to_hex(char ch)
{
	char	hex;

	hex = "0123456789abcdef"[ch / 16];
	write(1, &hex, 1);
	hex = "0123456789abcdef"[ch % 16];
	write(1, &hex, 1);
}

void	display_hex(char *addr, unsigned int now)
{
	unsigned int	idx;

	idx = 0;
	while (idx < now)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		to_hex(*(addr + idx));
		idx++;
	}
	while (idx < 16)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, " ", 1);
		write(1, " ", 1);
		idx++;
	}
	write(1, " ", 1);
}

void	display_contents(char *addr, unsigned int now)
{	
	unsigned int	idx;

	idx = 0;
	while ((now--) > 0)
	{
		if (*(addr + idx) >= 31 && *(addr + idx) <= 126)
		{
			write(1, addr + idx, 1);
		}
		else
			write(1, ".", 1);
		idx++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	now;
	void			*tmp;

	tmp = addr;
	now = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			now = 16;
		}
		else
		{
			now = size;
		}
		display_memory((unsigned long long)(tmp));
		display_hex((char *)tmp, now);
		display_contents((char *)tmp, now);
		write(1, "\n", 1);
		size -= now;
		tmp += now;
	}
	return (addr);
}
