/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:27:52 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/13 15:07:28 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <string.h>
# include "minilibx/mlx.h"

typedef struct t_map
{
	size_t	row;
	size_t	col;
	int		**map;
}	t_map;

void	draw(void);
char	**row_split(char *line);
void	free_all(char **split);
int		*convert_int(char **split, size_t col);
void	valid_file(char *filename);
void	valid_extension(char *filename);
void	ft_error(char *errmsg);
size_t	word_cnt(char **split);
int		validate(char **split);
t_map	*map_reader(char *filename);
#endif
