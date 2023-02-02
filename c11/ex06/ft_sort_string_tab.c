/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:50:50 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/30 21:23:24 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_word(char **tab)
{
	int	idx;

	idx = 0;
	while (*(tab + idx))
		idx++;
	return (idx);
}

int	cmp(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (0);
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (cmp(s1 + 1, s2 + 1));
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		n;
	char	*tmp;

	n = ft_word(tab);
	i = 0;
	while (i < n)
	{
		j = 1;
		while (j < n - i)
		{
			if (cmp(*(tab + j - 1), *(tab + j)) > 0)
			{
				tmp = *(tab + j - 1);
				*(tab + j - 1) = *(tab + j);
				*(tab + j) = tmp;
			}
			j++;
		}
		i++;
	}
}
