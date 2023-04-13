/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:22:35 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/31 10:39:20 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	idx;
	int	res;
	int	tmp;

	idx = 1;
	while (idx < length)
	{
		res = f(*(tab + (idx - 1)), *(tab + idx));
		if (res != 0)
			break ;
		idx++;
	}
	while (idx < length)
	{	
		tmp = f(*(tab + (idx - 1)),*(tab + idx));
		if (tmp < 0)
			tmp = -1;
		else if (tmp > 0)
			tmp = 1;
		if (res * tmp < 0)
			return (0);
		idx++;
	}
	return (1);
}
