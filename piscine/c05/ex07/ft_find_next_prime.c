/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:24:25 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/22 11:27:13 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_prime(int i)
{
	int	flag;
	int	j;

	while (1)
	{
		flag = 1;
		j = 2;
		while (j <= i / j)
		{
			if (i % j == 0)
			{
				flag = 0;
				break ;
			}
			j++;
		}
		if (flag)
			break ;
		i++;
	}
	return (i);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		i = 2;
	else
		i = nb;
	return (get_next_prime(i));
}
