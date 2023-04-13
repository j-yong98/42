/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:34:17 by spark2            #+#    #+#             */
/*   Updated: 2023/01/31 12:51:10 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	set_row(int flag)
{
	if (flag == 1)
		return (0);
	if (flag == 2)
		return (1);
	if (flag == 3)
		return (5);
	if (flag == 4)
		return (1);
	return (-1);
}

int	set_col(int flag)
{
	if (flag == 1)
		return (1);
	if (flag == 2)
		return (0);
	if (flag == 3)
		return (1);
	if (flag == 4)
		return (5);
	return (-1);
}

int	setting(char *av, int arr[6][6], int flag, int index)
{
	int	j_r;
	int	j_c;

	j_r = set_row(flag);
	j_c = set_col(flag);
	while ((index + 1) % 8 != 0)
	{
		if (index % 2 == 0)
		{
			if (*(av + index) >= '1' && *(av + index) <= '4')
			{
				arr[j_r][j_c] = *(av + index) - '0';
				if (flag % 2 == 1)
					j_c++;
				else
					j_r++;
			}
			else
				return (0);
		}
		else if (index % 2 == 1 && *(av + index) != ' ')
			return (0);
		index++;
	}
	return (1);
}

int	col_row_make(char **av, int arr[6][6])
{
	if (!setting(av[1], arr, 1, 0))
		return (-1);
	if (!setting(av[1], arr, 3, 8))
		return (-1);
	if (!setting(av[1], arr, 2, 16))
		return (-1);
	if (!setting(av[1], arr, 4, 24))
		return (-1);
	return (0);
}
