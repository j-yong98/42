/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:02:03 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 18:48:47 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		idx;
	char	ch;

	idx = 0;
	while (*(str + idx))
	{
		ch = *(str + idx);
		if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
			return (0);
		idx++;
	}
	return (1);
}
