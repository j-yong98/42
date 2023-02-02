/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:05:27 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/19 10:05:46 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (!*(to_find))
		return (str);
	while (*(str))
	{
		i = 0;
		while (*(str + i) == *(to_find + i))
		{
			if (!*(to_find + i))
				break ;
			i++;
		}
		if (!*(to_find + i))
			return (str);
		str++;
	}
	return (0);
}
