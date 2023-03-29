/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:39:37 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/26 09:21:50 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	a_size;
	int	i;
	int	*arr;

	a_size = max - min;
	arr = (int *)malloc(sizeof(int) * a_size);
	if (arr == NULL)
		return (0);
	i = 0;
	while (min <= max)
	{
		*(arr + i) = min++;
		i++;
	}
	return (arr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;

	if (min >= max)
		return (0);
	*range = ft_range(min, max);
	size = max - min;
	if (*range == 0)
		return (-1);
	return (size);
}
