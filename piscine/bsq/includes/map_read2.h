/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:49:13 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 16:23:43 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READ2_H
# define MAP_READ2_H

# define STDIN_MAX 4096

int		key_input(char **buf);
int		init_head(char *head);
void	init_buf(char *buf, int line);

#endif
