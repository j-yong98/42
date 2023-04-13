/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:40:22 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/11 16:07:14 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	int	*arr;

	if (argc == 1)
		return (0);
	arr = validate(++argv);
	return (0);
}
