/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:45:23 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/16 10:56:47 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (*(src + c) && c < n)
	{
		*(dest + c) = *(src + c);
		++c;
	}
	while (c < n)
	{
		*(dest + c) = '\0';
		++c;
	}
	return (dest);
}
