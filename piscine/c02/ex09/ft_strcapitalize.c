/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:19:10 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/17 18:50:54 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

int	is_upper(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	return (0);
}

int	is_lower(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		idx;
	char	pre_ch;

	idx = 0;
	while (*(str + idx))
	{
		if (is_alpha(*(str + idx)))
		{
			pre_ch = *(str + (idx - 1));
			if (idx == 0 || (!is_digit(pre_ch) && !is_alpha(pre_ch)))
			{
				if (is_lower(*(str + idx)))
					*(str + idx) -= 32;
			}
			else if (is_upper(*(str + idx)))
				*(str + idx) += 32;
		}
		idx++;
	}
	return (str);
}
