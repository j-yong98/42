/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:31:44 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/27 19:10:22 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * len + 1);
	while (*src)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock_array;
	int			idx;

	stock_array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_array)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		(stock_array + idx)->size = ft_strlen(*(av + idx));
		(stock_array + idx)->str = *(av + idx);
		(stock_array + idx)->copy = ft_strdup(*(av + idx));
		idx++;
	}
	(stock_array + idx)->str = 0;
	return (stock_array);
}
