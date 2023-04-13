/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:07:00 by jooypark          #+#    #+#             */
/*   Updated: 2023/01/29 22:52:05 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mynums.h"

int	check_key_exist(char *num, t_mynums *dict)
{
	int	i;
	int	check;

	while (dict)
	{
		i = 0;
		check = 0;
		while (dict->key[i] == num[i])
		{
			if (num[i + 1] == '\0')
				check = 1;
			i++;
		}
		dict = dict->next;
	}
	return (check);
}

int	print_key(char *num, t_mynums *dict)
{
	int	i;
	int	j;

	while (dict)
	{
		i = 0;
		while (dict->key[i] == num[i])
		{
			if (num[i + 1] == '\0')
			{
				j = 0;
				while (dict->value[j])
				{
					write(1, &(dict->value[j]), 1);
					j++;
				}
				return (1);
			}
			i++;
		}
		dict = dict->next;
	}
	return (0);
}
