/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:21:59 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/30 20:21:38 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (idx < length)
	{
		if (f(*(tab + idx)))
			cnt++;
		idx++;
	}
	return (cnt);
}
