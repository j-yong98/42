/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:27:52 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/18 14:00:47 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# define ESC 53
# define SIZE 800
# define DIST 50

typedef struct t_map
{
	size_t	row;
	size_t	col;
	int		**map;
}	t_map;

typedef struct t_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct t_pos
{
	int	now[2];
	int	next[2];
        int     color;
}	t_pos;

void	make_mlx(t_map *map);
void    draw_line(t_vars *vars, t_pos* pos);
void	draw(t_map *map, t_vars *vars);
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
