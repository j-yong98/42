/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:11:46 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/19 12:24:35 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	res = 1;
	i = 0;
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
