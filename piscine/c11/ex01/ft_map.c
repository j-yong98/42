/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:45:46 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/30 20:18:40 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	idx;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * length);
	if (arr == 0)
		return (0);
	idx = 0;
	while (idx < length)
	{
		*(arr + idx) = f(*(tab + idx));
		idx++;
	}
	return (arr);
}
