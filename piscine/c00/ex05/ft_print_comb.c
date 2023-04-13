/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:04 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/13 19:21:36 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	print_numbers(char i, char j, char k);

void	print_numbers(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i == '7' && j == '8' && k == '9')
		return ;
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '9')
	{
		j = i + 1;
		while (j <= '9')
		{
			k = j + 1;
			while (k <= '9')
			{
				print_numbers(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
