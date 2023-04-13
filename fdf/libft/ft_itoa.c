/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:34:12 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/23 10:39:51 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(unsigned int num, int sign)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	if (sign < 0)
		return (len + 1);
	return (len);
}

static size_t	to_char(char *ptr, unsigned int num)
{
	size_t	len;

	len = 0;
	if (num / 10 == 0)
	{
		*(ptr + len) = (num % 10) + '0';
		return (len + 1);
	}
	len += to_char(ptr, num / 10);
	*(ptr + len) = (num % 10) + '0';
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	int				sign;
	unsigned int	tmp;
	size_t			len;

	sign = 1;
	if (n < 0)
		sign = -1;
	tmp = n;
	if (sign < 0)
		tmp = -n;
	len = get_len(tmp, sign);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (sign < 0 && tmp > 0)
	{
		*ptr = '-';
		to_char(ptr + 1, tmp);
	}
	else
		to_char(ptr, tmp);
	*(ptr + len) = 0;
	return (ptr);
}
