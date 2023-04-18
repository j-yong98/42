/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:50 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/18 13:47:34 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strllen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

size_t	ft_strllcpy(char *dst, char *src, size_t len, size_t s_len)
{
	size_t	idx;

	idx = 0;
	while (idx < s_len && idx + 1 < len)
	{
		*(dst + idx) = *(src + idx);
		idx++;
	}
	if (len > 0)
		*(dst + idx) = 0;
	return (s_len);
}

size_t	ft_strllcat(char *dst, char *src, size_t len)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;

	d_len = ft_strllen(dst);
	s_len = ft_strllen(src);
	if (d_len > len)
		return (s_len + len);
	idx = 0;
	while (idx < s_len && d_len + idx + 1 < len)
	{
		*(dst + d_len + idx) = *(src + idx);
		idx++;
	}
	*(dst + d_len + idx) = 0;
	return (d_len + s_len);
}

void	*ft_expand(void *ptr, size_t size, int len)
{
	void	*dst;

	if (!ptr)
	{
		dst = malloc(size + 1);
		if (!dst)
			return (NULL);
		*(char *)dst = 0;
		return (dst);
	}
	if (size == 0)
		return (NULL);
	dst = malloc(len + size + 1);
	if (!dst)
	{
		free(ptr);
		return (NULL);
	}
	ft_strllcpy((char *)dst, (char *)ptr, len + size + 1, len);
	free(ptr);
	return (dst);
}
