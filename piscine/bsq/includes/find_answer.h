/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_answer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:39:11 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 20:39:56 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_ANSWER_H
# define FIND_ANSWER_H

# include "find_answer2.h"

int		find_square(t_info *info);
void	set_dp(t_info *info, int **dp);
int		get_min_value(int **dp, int i, int j);
void	find_max_scale(int **dp, t_square *sq, int r, int c);
void	draw_sq(t_info *info, t_square *sq);

#endif
