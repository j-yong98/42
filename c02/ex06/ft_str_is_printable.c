/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:41:28 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/16 22:10:51 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (!is_printable(*(str + idx)))
			return (0);
		idx++;
	}
	return (1);
}
