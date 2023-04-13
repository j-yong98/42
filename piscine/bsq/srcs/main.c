/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:13:15 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 21:22:29 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			solve(argv[i]);
			i++;
		}
	}
	else
	{
		solve(NULL);
	}
	exit(0);
	return (0);
}
