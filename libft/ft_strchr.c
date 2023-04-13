/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:38:59 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/14 21:15:59 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	unsigned char	*tmp;

	ch = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (*tmp)
	{
		if (*tmp == ch)
			return ((char *)tmp);
		tmp++;
	}
	if (*tmp == ch)
		return ((char *)tmp);
	return (0);
}
