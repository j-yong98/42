/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:31 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/30 10:57:32 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(char *a, char *b)
{
	if (!*a && !*b)
		return (0);
	if (*a != *b)
		return (*a - *b);
	return (compare(a + 1, b + 1));
}

void	ft_print(char *argv)
{
	while (*argv)
	{
		write(1, argv, 1);
		argv++;
	}
	write(1, "\n", 1);
}

void	print_argv(int n, char **argv)
{
	int	i;

	i = 1;
	while (i < n)
	{
		ft_print(argv[i]);
		i++;
	}
}

void	sort(int n, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < n)
	{
		j = 1;
		while (j < n - i)
		{
			if (compare(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	sort(argc, argv);
	print_argv(argc, argv);
	return (0);
}
