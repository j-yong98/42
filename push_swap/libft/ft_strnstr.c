/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:36:12 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/14 21:05:33 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	idx;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		idx = 0;
		while (*(haystack + idx) == *(needle + idx) && i + idx < len)
		{
			if (!*(needle + idx))
				break ;
			idx++;
		}
		if (!*(needle + idx))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
