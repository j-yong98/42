/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:18:50 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/13 18:40:47 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_pos *pos, t_vars *vars, int color)
{
	int	x;
	int	y;
	int	dy;
	int	dx;
	int	p;

	y = pos->now[0];
	x = pos->now[1];
	dy = abs(pos->now[0] - pos->next[0]);
	dx = abs(pos->now[1] - pos->next[1]);
	p = 2*dy - dx;
	while (x <= pos->next[1])
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, color);
		x++;
		if (p < 0)
			p += 2*dy;
		else
		{
			p += 2*dy - 2*dx;
			y++;
		}
	}
}

int	get_color(int val)
{
	return ((255 + 255) + (255 << val));
}
void	draw(t_map *map, t_vars *vars)
{
	t_pos	pos;

	/*
	for (int i = 0; i < (int)map->row; i++) {
		for (int j = 0; j < (int)map->col; j++) {
				pos.now[0] = i * DIST + DIST;
				pos.now[1] = j * DIST + DIST;
				pos.next[0] = i * DIST + DIST;
				pos.next[1] = (j + 1) * DIST + DIST;
				bresenham(&pos ,vars);
		}
	}
	*/
	for (int i = 0; i < (int)map->row; i++) {
		for (int j = 0; j < (int)map->row; j++) {
			pos.now[0] = i * DIST + DIST;
			pos.now[1] = j * DIST + DIST;
			pos.next[0] = (i + 1) * DIST + DIST;
			pos.next[1] = j * DIST * 2 + DIST;
			bresenham(&pos, vars, get_color(map->map[i][j]));
		}
	}
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	make_mlx(t_map *map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map->row * SIZE, map->col * SIZE, "test");
	draw(map, &vars);
	mlx_key_hook(vars.win, close_win, &vars);
	mlx_loop(vars.mlx);
}
