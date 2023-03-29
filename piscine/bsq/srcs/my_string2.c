/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:53 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 20:42:40 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "info.h"
#include "square.h"
#include "my_string2.h"

void	my_putstr(char *str)
{
	char	*sp;

	sp = str;
	while (*sp != '\0')
		write(1, sp++, 1);
	return ;
}

void	my_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	my_putmap(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->line)
	{
		j = 0;
		while (j < info->linelen)
		{
			my_putchar(info->map[i][j]);
			j++;
		}
		my_putchar('\n');
		i++;
	}
	return ;
}
