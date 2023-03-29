/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:03:25 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 22:29:59 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	unsigned int	idx;

	idx = 0;
	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	while ((*(u_s1) || *(u_s2)) && idx < n)
	{
		if (*(u_s1) != *(u_s2))
			return (*(u_s1) - *(u_s2));
		u_s1++;
		u_s2++;
		idx++;
	}
	return (0);
}
