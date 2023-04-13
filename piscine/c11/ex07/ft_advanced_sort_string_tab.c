/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:10:52 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/30 21:18:56 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_word(char **arr)
{
	int	len;

	len = 0;
	while (*(arr + len))
		len++;
	return (len);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
				tmp = *(tab + j);
				*(tab + j) = *(tab + j - 1);
				*(tab + j - 1) = tmp;
			}
			j++;
		}
		i++;
	}
}
