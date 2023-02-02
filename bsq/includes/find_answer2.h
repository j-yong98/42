/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_answer2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:47:03 by jelee2            #+#    #+#             */
/*   Updated: 2023/02/01 21:07:32 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_ANSWER2_H
# define FIND_ANSWER2_H

# include "square.h"

int		**dp_init(t_info *info);
void	dp_free(t_info *info, int **dp);
void	side_init(t_info *info, int **dp);
void	square_init(t_square *sq);

#endif
