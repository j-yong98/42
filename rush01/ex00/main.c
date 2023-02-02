/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:19:57 by spark2            #+#    #+#             */
/*   Updated: 2023/01/24 10:40:25 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		make_answer(int r, int c, int arr[6][6]);
void	col_row_make(char **av, int arr[6][6]);

void	init(int arr[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
			arr[i][j++] = 0;
		i++;
	}
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	arr[6][6];
	int	flag;

	init(arr);
	if (ac != 2 || ft_len(av[1]) != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	col_row_make(av, arr);
	flag = make_answer(1, 1, arr);
	if (!flag)
		write(1, "Error\n", 6);
	return (0);
}
