/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:43:27 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/16 14:26:22 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_low_alpha(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (is_low_alpha(*(str + idx)))
		{
			*(str + idx) = *(str + idx) - 32;
		}
		++idx;
	}
	return (str);
}
