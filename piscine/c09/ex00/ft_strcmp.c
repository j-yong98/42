/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:28:44 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/27 22:39:35 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (*(s1 + idx) && *(s2 + idx))
	{
		if (*(s1 + idx) != *(s2 + idx))
			return (*(s1 + idx) - *(s2 + idx));
		idx++;
	}
	return (*(s1 + idx) - *(s2 + idx));
}
