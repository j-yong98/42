/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:51:37 by jelee2            #+#    #+#             */
/*   Updated: 2023/01/31 13:02:47 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR -1
# define SUCCESS 0

int		check_map(char *map, t_info *info);
void	init_check_map(char *map, int *linelen, int *linecnt, int *nl_cnt);
void	mp_newline(int *linecnt, int *nl_cnt);
int		mp_in_head(char c, t_info *info);

#endif
