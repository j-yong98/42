/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:04:05 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/02/02 10:37:00 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_charset(char *str, char *charset)
{
	if (!*charset)
		return (0);
	if (*str == *charset)
		return (find_charset(str + 1, charset + 1) + 1);
	return (find_charset(str, charset + 1));
}

int	get_word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (find_charset(str++, charset) != 0)
			break ;
		len++;
	}
	return (len);
}

int	rm_front_charset(char *str, char *charset)
{
	int	find_idx;
	int	len;

	len = 0;
	while (1)
	{
		find_idx = find_charset(str + len, charset);
		if (find_idx == 0)
			break ;
		len++;
	}
	return (len);
}

int	word_cnt(char *str, char *charset)
{
	int	len;
	int	char_len;
	int	word_len;
	int	cnt;

	cnt = 0;
	len = 0;
	while (*(str + len))
		len++;
	while (len > 0)
	{
		char_len = rm_front_charset(str, charset);
		str += char_len;
		len -= char_len;
		if (len <= 0)
			break ;
		word_len = get_word_len(str, charset);
		cnt++;
		str += word_len;
		len -= word_len;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		r_idx;
	int		c_idx;
	int		w_cnt;
	int		w_len;

	r_idx = 0;
	w_cnt = word_cnt(str, charset);
	arr = (char **)malloc(sizeof(char *) * (w_cnt + 1));
	while (r_idx < w_cnt)
	{
		str += rm_front_charset(str, charset);
		c_idx = 0;
		w_len = get_word_len(str, charset);
		*(arr + r_idx) = malloc(sizeof(char) * (w_len + 1));
		while (w_len-- > 0)
			*(*(arr + r_idx) + c_idx++) = *str++;
		*(*(arr + r_idx) + c_idx) = '\0';
		r_idx++;
	}
	*(arr + r_idx) = NULL;
	return (arr);
}
