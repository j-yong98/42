/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:48:54 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/26 09:29:34 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	a_size;
	int	i;
	int	*arr;

	if (min >= max)
		return (0);
	a_size = max - min;
	arr = (int *)malloc(sizeof(int) * a_size);
	if (arr == NULL)
		return (0);
	i = 0;
	while (min < max)
	{
		*(arr + i) = min++;
		i++;
	}
	return (arr);
}
