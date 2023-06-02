/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:31:40 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/06/02 12:51:34 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	validate(int ac, char *av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("Illegal Argument!\n");
		return (-1);
	}
	pid = ft_atoi(av);
	if (pid <= 100 || pid >= 99999)
	{
		ft_printf("PID Error\n");
		return (-1);
	}
	return (pid);
}
