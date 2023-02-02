/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:01:25 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/12 21:23:25 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	my_func(int i);
void	print_number(char *arr);
void	make_char_number(int n);

void	print_number(char *arr)
{
	write(1, arr, 2);
}

void	make_char_number(int n)
{
	int		idx;
	char	arr[2];

	idx = 1;
	while (idx >= 0)
	{
		arr[idx] = (n % 10) + '0';
		idx--;
		n /= 10;
	}
	print_number(arr);
}

void	my_func(int i)
{
	int		j;
	char	space;

	space = ' ';
	j = i + 1;
	while (j < 100)
	{
		make_char_number(i);
		write(1, &space, 1);
		make_char_number(j);
		if (i == 98 && j == 99)
			break ;
		write(1, ", ", 2);
		j++;
	}
}

void	ft_print_comb2(void)
{
	int	i;

	i = 0;
	while (i < 99)
	{
		my_func(i);
		i++;
	}
}
