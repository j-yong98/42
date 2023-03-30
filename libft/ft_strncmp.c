/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:13:37 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/17 21:41:30 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;
	size_t				len;

	u_s1 = (const unsigned char *) s1;
	u_s2 = (const unsigned char *) s2;
	len = 0;
	while ((*(u_s1 + len) || *(u_s2 + len)) && len < n)
	{
		if (*(u_s1 + len) != *(u_s2 + len))
			return (*(u_s1 + len) - *(u_s2 + len));
		len++;
	}
	return (0);
}
