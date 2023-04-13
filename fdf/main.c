/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:29:18 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/12 20:23:17 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *errmsg)
{
	printf("Error : %s\n", errmsg);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (0);
	valid_extension(argv[1]);
	valid_file(argv[1]);
	map = map_reader(argv[1]);
	draw();
	return (0);
}
