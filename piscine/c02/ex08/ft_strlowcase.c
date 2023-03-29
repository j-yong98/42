/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:43:10 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 18:50:37 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper_alpha(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (is_upper_alpha(*(str + idx)))
		{
			*(str + idx) += 32;
		}
		idx++;
	}
	return (str);
}
