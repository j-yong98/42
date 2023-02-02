/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:21:19 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/16 14:22:09 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	len;

	idx = 0;
	len = ft_strlen(src);
	while (idx < len && idx + 1 < size)
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	if (size > 0)
	{
		*(dest + idx) = '\0';
	}
	return (len);
}
