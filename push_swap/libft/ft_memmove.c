/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:52:38 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/17 14:31:39 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	l;

	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		l = 0;
		while (l < len)
		{
			*((char *)(dst + l)) = *((char *)(src + l));
			l++;
		}
	}
	else
	{
		while (len--)
			*((char *)(dst + len)) = *((char *)(src + len));
	}
	return (dst);
}
