/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:53:28 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/21 20:41:40 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	idx;

	if (argc < 2)
		return (0);
	idx = 1;
	while (idx < argc)
	{
		while (*(argv[idx]))
		{
			write(1, argv[idx], 1);
			argv[idx]++;
		}
		write(1, "\n", 1);
		idx++;
	}
	return (0);
}
