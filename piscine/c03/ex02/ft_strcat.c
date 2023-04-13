/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:19:07 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 16:43:19 by jaeychoi         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	dest_idx;
	int	src_idx;

	dest_idx = get_length(dest);
	src_idx = 0;
	while (*(src + src_idx))
	{
		*(dest + dest_idx) = *(src + src_idx);
		dest_idx++;
		src_idx++;
	}
	*(dest + dest_idx) = '\0';
	return (dest);
}
