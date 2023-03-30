/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:48:48 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/15 17:44:09 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	*tmp;
	unsigned char	ch;

	len = ft_strlen(s);
	tmp = (unsigned char *)s;
	ch = (unsigned char) c;
	while (len)
	{
		if (*(tmp + len) == ch)
			return ((char *)(tmp + len));
		len--;
	}
	if (*(tmp + len) == ch)
		return ((char *)(tmp + len));
	return (0);
}
