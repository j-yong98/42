/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:42:25 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/11 22:18:06 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_row(char *filename)
{
	size_t	row;
	int		fd;
	char	*line;

	row = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		row++;
	}
	if (read(fd, NULL, 1) != 0)
		ft_error("Read Error");
	close(fd);
	return (row);
}

size_t	get_col(char *filename)
{
	int		fd;
	char	*line;
	char	**split;
	size_t	pre;

	pre = 0;
	split = NULL;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = row_split(line);
		if (!split || (pre != 0 && pre != word_cnt(split)))
			ft_error("Invaild Map");
		pre = word_cnt(split);
		free_all(split);
	}
	if (read(fd, NULL, 1) != 0)
		ft_error("Read Error");
	close(fd);
	return (pre);
}

char	**read_col(int fd, size_t col)
{
	char	*line;
	char	**split;
	size_t	cnt;

	line = get_next_line(fd);
	split = NULL;
	if (!line)
	{
		if (read(fd, NULL, 1) != 0)
			ft_error("Read Error");
	}
	split = row_split(line);
	cnt = word_cnt(split);
	if (cnt != col || !validate(split))
		ft_error("Invalid Map");
	return (split);
}

int	**read_map(char *filename, size_t row, size_t col)
{
	char	**split;
	int		fd;
	int		**map;
	size_t	idx;

	fd = open(filename, O_RDONLY);
	map = (int **)malloc(sizeof(int *) * row);
	if (!map)
		ft_error("Allocation Error");
	idx = 0;
	while (idx < row)
	{
		split = read_col(fd, col);
		*(map + idx) = convert_int(split, col);
		idx++;
		free_all(split);
	}
	close(fd);
	return (map);
}

t_map	*map_reader(char *filename)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->row = get_row(filename);
	map->col = get_col(filename);
	map->map = read_map(filename, map->row, map->col);
	return (map);
}
