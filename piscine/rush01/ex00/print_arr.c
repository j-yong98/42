/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:20:22 by spark2            #+#    #+#             */
/*   Updated: 2023/01/22 21:06:49 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_map(int arr[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			ft_putchar(arr[i][j] + '0');
			if (j != 4)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
