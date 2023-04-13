/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:29:07 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/11 17:56:59 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	in_integer(char *str)
{
	char	*tmp;
	size_t	len;
	size_t	idx;

	tmp = "2147483647";
	if (*str == '-')
		tmp = "2147483648";
	if (*str == '-' || *str == '+')
		str++;
	len = ft_strlen(str);
	if (len > 10)
		print_error();
	if (len < 10)
		return ;
	idx = 0;
	while (idx < len)
	{
		if (*(str + idx) > *(tmp + idx))
			print_error();
		idx++;
	}
}

static void	is_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		str++;
	}
}

static size_t	word_cnt(char **split)
{
	size_t	len;

	len = 0;
	while (*(split + len))
		len++;
	return (len);
}

static int	is_duplicate(int *res, char *str)
{
	int		num;
	size_t	idx;

	num = ft_atoi(str);
	idx = 0;
	while (*(res + idx))
	{
		if (num == *(res + idx))
			print_error();
		idx++;
	}
	return (num);
}

int	*validate(char **argv)
{
	int		*res;
	char	**split;
	size_t	cnt;
	size_t	r_idx;
	size_t	idx;

	res = (int *)malloc(sizeof(int));
	r_idx = 0;
	while (*argv)
	{
		split = ft_split(*argv, ' ');
		cnt = word_cnt(split);
		idx = 0;
		while (cnt--)
		{
			is_number(*(split + idx));
			in_integer(*(split + idx));
			*(res + r_idx) = is_duplicate(res, *(split + idx));
			r_idx++;
			idx++;
		}
		argv++;
	}
	return (res);
}
