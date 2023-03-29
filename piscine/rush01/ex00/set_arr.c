/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:20:33 by spark2            #+#    #+#             */
/*   Updated: 2023/01/31 12:50:51 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		can_up(int arr[6][6]);
int		can_down(int arr[6][6]);
int		can_left(int arr[6][6]);
int		can_right(int arr[6][6]);
void	print_map(int arr[6][6]);

int	is_validate(int arr[6][6])
{
	if (!can_up(arr))
		return (0);
	if (!can_down(arr))
		return (0);
	if (!can_left(arr))
		return (0);
	if (!can_right(arr))
		return (0);
	return (1);
}

int	is_dup(int r, int c, int v, int arr[6][6])
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (v == arr[r][i])
			return (1);
		if (v == arr[i][c])
			return (1);
		i++;
	}
	return (0);
}

int	make_answer(int r, int c, int arr[6][6])
{

	int	is_finish;
	int	value;

	is_finish = 0;
	if (r == 5 && is_validate(arr))
	{
		print_map(arr);
		return (1);
	}
	value = 0;
	while (++value <= 4)
	{
		if (!is_dup(r, c, value, arr))
		{
			arr[r][c] = value;
			if (c + 1 == 5)
				is_finish = make_answer(r + 1, 1, arr);
			else
				is_finish = make_answer(r, c + 1, arr);
			arr[r][c] = 0;
			if (is_finish)
				return (is_finish);
		}
	}
	return (is_finish);
}
