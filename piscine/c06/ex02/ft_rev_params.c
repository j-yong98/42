/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:00:07 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/21 20:41:49 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	idx;

	if (argc < 2)
		return (0);
	idx = argc - 1;
	while (idx >= 1)
	{
		while (*argv[idx])
		{
			write(1, argv[idx], 1);
			argv[idx]++;
		}
		idx--;
		write(1, "\n", 1);
	}
	return (0);
}
