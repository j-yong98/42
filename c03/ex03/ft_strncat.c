/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:27:38 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 16:45:37 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_length(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		idx++;
	}
	return (idx);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_idx;
	unsigned int	src_idx;

	dest_idx = get_length(dest);
	src_idx = 0;
	while (*(src + src_idx) && src_idx < nb)
	{
		*(dest + dest_idx) = *(src + src_idx);
		src_idx++;
		dest_idx++;
	}
	*(dest + dest_idx) = '\0';
	return (dest);
}
