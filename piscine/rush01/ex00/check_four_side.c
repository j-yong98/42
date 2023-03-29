/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_four_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:20:15 by spark2            #+#    #+#             */
/*   Updated: 2023/01/24 10:22:07 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	can_up(int arr[6][6])
{
	int	i;
	int	j;
	int	sight;
	int	max;
	int	cnt;

	i = 0;
	while (++i < 5)
	{
		sight = arr[0][i];
		max = arr[1][i];
		cnt = 1;
		j = 0;
		while (++j < 5)
		{
			if (arr[j][i] > max)
			{
				max = arr[j][i];
				cnt++;
			}
		}
		if (cnt != sight)
			return (0);
	}
	return (1);
}

int	can_down(int arr[6][6])
{
	int	i;
	int	j;
	int	sight;
	int	max;
	int	cnt;

	i = 0;
	while (++i < 5)
	{
		sight = arr[5][i];
		max = arr[4][i];
		cnt = 1;
		j = 5;
		while (--j > 0)
		{
			if (arr[j][i] > max)
			{
				max = arr[j][i];
				cnt++;
			}
		}
		if (cnt != sight)
			return (0);
	}
	return (1);
}

int	can_left(int arr[6][6])
{
	int	i;
	int	j;
	int	sight;
	int	max;
	int	cnt;

	i = 0;
	while (++i < 5)
	{
		sight = arr[i][0];
		cnt = 1;
		max = arr[i][1];
		j = 0;
		while (++j < 5)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				cnt++;
			}
		}
		if (cnt != sight)
			return (0);
	}
	return (1);
}

int	can_right(int arr[6][6])
{
	int	i;
	int	j;
	int	sight;
	int	max;
	int	cnt;

	i = 0;
	while (++i < 5)
	{
		sight = arr[i][5];
		cnt = 1;
		max = arr[i][4];
		j = 5;
		while (--j > 0)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				cnt++;
			}
		}
		if (cnt != sight)
			return (0);
	}
	return (1);
}
