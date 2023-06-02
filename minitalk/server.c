/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:31:46 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/06/02 13:20:29 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	*g_message;

void	get_signal(int signal)
{
	int	ret;

	if (signal == SIGUSR1)
		g_message->ch |= 0;
	else
		g_message->ch |= 1;
	if (g_message->bit < 7)
		g_message->ch <<= 1;
	g_message->bit++;
	if (g_message->bit == 8)
	{
		ret = write(1, &g_message->ch, 1);
		if (ret < 0)
			exit(0);
		g_message->bit = 0;
		g_message->ch = 0;
	}
}

int	main(void)
{
	int	ret;

	g_message = (t_message *)malloc(sizeof(t_message));
	ret = ft_printf("SERVER START, PID : %d\n", getpid());
	if (ret < 0)
		exit(0);
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
	free(g_message);
}
