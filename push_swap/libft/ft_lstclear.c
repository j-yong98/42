/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:07:18 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/17 13:55:08 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*node;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node;
		node = node->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
