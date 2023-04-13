/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:02:13 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/24 12:50:48 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	len = 0;
	while (len < s_len && d_len + len + 1 < size)
	{
		*(dst + d_len + len) = *(src + len);
		len++;
	}
	*(dst + d_len + len) = 0;
	if (d_len < size)
		return (s_len + d_len);
	return (s_len + size);
}
