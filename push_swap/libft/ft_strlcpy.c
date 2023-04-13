/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:39:07 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/24 12:50:53 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	s_len;

	len = 0;
	s_len = ft_strlen(src);
	while (len < s_len && len + 1 < dstsize)
	{
		*(dst + len) = *(src + len);
		len++;
	}
	if (dstsize > 0)
		*(dst + len) = 0;
	return (s_len);
}
