/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:01:18 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/21 21:53:00 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	delim_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len))
	{
		if (*(s + len) != c)
			break ;
		len++;
	}
	return (len);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len))
	{
		if (*(s + len) == c)
			break ;
		len++;
	}
	return (len);
}

static size_t	word_cnt(char const *s, char c)
{
	size_t	cnt;
	size_t	d_len;
	size_t	w_len;

	cnt = 0;
	while (*s)
	{
		d_len = delim_len(s, c);
		s += d_len;
		if (!*s)
			break ;
		w_len = word_len(s, c);
		s += w_len;
		cnt++;
	}
	return (cnt);
}

static char	**free_all(char **ptr)
{
	size_t	idx;

	idx = 0;
	while (*(ptr + idx))
	{
		free(*(ptr + idx));
		idx++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	w_cnt;
	size_t	w_len;
	size_t	r;

	w_cnt = word_cnt(s, c);
	ptr = (char **)malloc(sizeof(char *) * (w_cnt + 1));
	if (!ptr)
		return (NULL);
	r = 0;
	while (r < w_cnt)
	{
		s += delim_len(s, c);
		w_len = word_len(s, c);
		*(ptr + r) = (char *)malloc(sizeof(char) * (w_len + 1));
		if (!*(ptr + r))
			return (free_all(ptr));
		ft_strlcpy(*(ptr + r), s, w_len + 1);
		s += w_len;
		r++;
	}
	*(ptr + r) = 0;
	return (ptr);
}
