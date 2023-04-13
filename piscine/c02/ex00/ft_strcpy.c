/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:21:48 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/16 14:40:46 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (*(src + idx))
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	*(dest + idx) = '\0';
	return (dest);
}
