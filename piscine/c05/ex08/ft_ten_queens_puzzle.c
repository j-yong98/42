/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:57:17 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/19 12:29:18 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int board[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	board_check(int row, int col, int board[10][10])
{
	int	i;

	i = 1;
	while (i <= row)
	{
		if (row - i >= 0 && board[row - i][col] == 1)
			return (0);
		if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 1)
			return (0);
		if (row - i >= 0 && col + i < 10 && board[row - i][col + i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	calc(int board[10][10], int row)
{
	int	col;
	int	cnt;

	if (row == 10)
	{
		print_board(board);
		return (1);
	}
	col = 0;
	cnt = 0;
	while (col < 10)
	{
		if (board_check(row, col, board))
		{
			board[row][col] = 1;
			cnt += calc(board, row + 1);
			board[row][col] = 0;
		}
		col++;
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (calc(board, 0));
}
