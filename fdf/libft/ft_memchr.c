/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:57:21 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/15 11:39:22 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tmp;
	unsigned char	*ptr;
	size_t			len;

	len = 0;
	tmp = (unsigned char) c;
	ptr = (unsigned char *) s;
	while (len < n)
	{
		if (*ptr == tmp)
			return ((void *) ptr);
		ptr++;
		len++;
	}
	return (0);
}
