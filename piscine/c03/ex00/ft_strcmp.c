/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:49:05 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 16:38:19 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				idx;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	idx = 0;
	while (*(u_s1 + idx) && *(u_s2 + idx))
	{
		if (*(u_s1 + idx) != *(u_s2 + idx))
			break ;
		idx++;
	}
	return (*(u_s1 + idx) - *(u_s2 + idx));
}
