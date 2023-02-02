/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:16:21 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/12 18:07:27 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	f(int n, int s, int l, char *arr);
void	print_arr(char *c, int n);

void	print_arr(char *c, int n)
{
	write(1, c, n);
	if (c[0] == (10 - n) + '0')
	{
		return ;
	}
	write(1, ", ", 2);
}

void	f(int n, int s, int l, char *arr)
{
	if (l == n)
	{
		print_arr(arr, n);
		return ;
	}
	while (s + '0' <= '9')
	{
		arr[l] = s + '0';
		f(n, s + 1, l + 1, arr);
		s++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	f(n, 0, 0, arr);
}
