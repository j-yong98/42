/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:33:09 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/30 19:27:58 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mynums.h"

t_mynums	*new_node(void)
{
	t_mynums	*node;

	node = (t_mynums *)malloc(sizeof(t_mynums));
	node->next = 0;
	return (node);
}

t_mynums	*get_last_node(t_mynums *head)
{
	while (head->next != 0)
	{
		head = head->next;
	}
	return (head);
}

char	*read_dict(char *file_path)
{
	char		buf;
	int			fd;
	int			len;
	char		*dict;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	len = 0;
	while (read(fd, &buf, 1))
		len++;
	close(fd);
	dict = (char *)malloc(sizeof(char) * (len + 1));
	fd = open(file_path, O_RDONLY);
	read(fd, dict, len);
	*(dict + (len)) = 0;
	close(fd);
	return (dict);
}

int	make_malloc(t_mynums *node, char *dict, char *charset)
{
	char	*k_v;
	int		idx;
	int		len;

	len = 0;
	while (*(dict + len) && *(dict + len) != *charset)
		len++;
	k_v = (char *)malloc(sizeof(char) * len + 1);
	idx = 0;
	while (idx < len)
	{
		*(k_v + idx) = *(dict + idx);
		idx++;
	}
	*(dict + len) = 0;
	if (*charset == ':')
		node->key = k_v;
	else
		node->value = k_v;
	return (len + 1);
}

t_mynums	*make_dict(char *dict)
{
	t_mynums	*node;
	t_mynums	*cur;
	t_mynums	*head;

	head = new_node();
	while (*dict)
	{
		node = new_node();
		dict += make_malloc(node, dict, ":");
		if (!is_validate_key(node->key))
			return (0);
		while (*dict && is_space(*dict))
			dict++;
		dict += make_malloc(node, dict, "\n");
		cur = get_last_node(head);
		cur->next = node;
	}
	return (head);
}
