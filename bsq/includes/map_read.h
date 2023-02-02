/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:46:57 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 15:06:40 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READ_H
# define MAP_READ_H

# include "map_read2.h"

int	set_info(t_info *info, char *filename);
int	alloc_map(t_info *info, char *cp);
int	read_header(char *header, t_info *info);
int	read_contents(char **contents, char *filename, char **buf);
int	flen(char *filename, char **buf);

#endif
