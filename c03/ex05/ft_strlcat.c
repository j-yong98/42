/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:13:59 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 22:28:51 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	idx;

	d_len = 0;
	s_len = 0;
	while (*(dest + d_len))
		d_len++;
	while (*(src + s_len))
		s_len++;
	idx = 0;
	while (*(src + idx) && d_len + idx + 1 < size)
	{
		*(dest + d_len + idx) = *(src + idx);
		idx++;
	}
	*(dest + d_len + idx) = '\0';
	if (d_len < size)
		return (s_len + d_len);
	else
		return (size + s_len);
}
