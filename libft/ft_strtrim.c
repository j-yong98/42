/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:38:25 by jaeychoi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/04 15:11:01 by jaeychoi         ###   ########.fr       */
=======
/*   Updated: 2023/03/17 14:46:26 by jaeychoi         ###   ########.fr       */
>>>>>>> bfd7205452947754ad6a438d8d5f1739a5f727ae
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;

	while (*s1)
	{
		if (ft_strchr(set, *s1))
			s1++;
		else
			break ;
	}
	len = ft_strlen(s1) - 1;
	while (*s1 && len + 1 > 0)
	{
		if (ft_strchr(set, *(s1 + len)))
			len--;
		else
			break ;
	}
	ptr = (char *)malloc(sizeof(char) * len + 2);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len + 2);
	return (ptr);
}
