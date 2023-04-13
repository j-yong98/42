/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroh <sroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:05:16 by sroh              #+#    #+#             */
/*   Updated: 2023/01/15 14:49:46 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	argv_char_to_int(char *argv)
{
	int	argv_int;
	int	idx;

	argv_int = 0;
	idx = 0;
	while (*(argv + idx))
	{
		argv_int *= 10;
		argv_int += argv[idx] - '0';
		idx++;
	}
	return (argv_int);
}

void	error_print(int error_num)
{
	if (error_num == 1)
	{
		write(1, "Few Arguments\n", 14);
	}
	if (error_num == 2)
	{
		write(1, "Too Many Arguments\n", 19);
	}
	if (error_num == 3)
	{
		write(1, "Input Correct Number\n", 21);
	}
}

int	is_digit(char *argv)
{
	int	idx;

	idx = 0;
	while (*(argv + idx))
	{
		if (*(argv + idx) < '1' || *(argv + idx) > '9')
			return (0);
		idx++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc == 3 && is_digit(argv[1]) && is_digit(argv[2]))
	{	
		x = argv_char_to_int(argv[1]);
		y = argv_char_to_int(argv[2]);
		rush(x, y);
		return (0);
	}
	if (argc < 3)
		error_print(1);
	else if (argc > 3)
		error_print(2);
	else if (argc == 3)
		error_print(3);
	return (0);
}
