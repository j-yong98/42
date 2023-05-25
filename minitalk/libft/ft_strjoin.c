/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:14:10 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/16 11:38:05 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	l_s1;
	size_t	l_s2;
	size_t	l;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (!ptr)
		return (NULL);
	l = 0;
	while (l < l_s1)
	{
		*(ptr + l) = *(s1 + l);
		l++;
	}
	l = 0;
	while (l < l_s2)
	{
		*(ptr + l_s1 + l) = *(s2 + l);
		l++;
	}
	*(ptr + l_s1 + l_s2) = 0;
	return (ptr);
}
