/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:00:57 by jelee2            #+#    #+#             */
/*   Updated: 2023/01/31 14:42:12 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef struct s_info
{
	int		line;
	int		linelen;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
}	t_info;

#endif
