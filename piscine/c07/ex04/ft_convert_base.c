/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:10:54 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/25 11:06:09 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		to_int(char *str, char *base_from, int f_len);
char	*convert_base_to(int num, char *base_to, int t_len, int sing);

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	if (ch == '\r' || ch == '\r' || ch == '\f')
		return (1);
	return (0);
}

char	*rm_space(char *nbr)
{
	while (*nbr && is_space(*nbr))
		nbr++;
	return (nbr);
}

int	get_sign(char *nbr)
{
	int	sign;

	sign = 1;
	while (*nbr && (*nbr == '-' || *nbr == '+'))
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	return (sign);
}

int	base_check(char *base)
{
	char	c;
	int		len;
	int		j;

	len = 0;
	while (*(base + len))
	{
		c = *(base + len);
		j = len + 1;
		if (is_space(c) || c == '-' || c == '+')
			return (0);
		while (*(base + j))
		{
			if (*(base + len) == *(base + j))
				return (0);
			j++;
		}
		len++;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	convert_int;
	int	sign;
	int	t_len;
	int	f_len;

	f_len = base_check(base_from);
	t_len = base_check(base_to);
	if (f_len < 2 || t_len < 2)
		return (0);
	nbr = rm_space(nbr);
	sign = get_sign(nbr);
	while (*nbr && (*nbr == '-' || *nbr == '+'))
		nbr++;
	convert_int = to_int(nbr, base_from, f_len);
	return (convert_base_to(convert_int, base_to, t_len, sign));
}
