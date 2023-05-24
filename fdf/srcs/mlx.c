/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:18:50 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/14 18:12:48 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int val)
{
	return ((255 + 255) + (255 << val));
}
void	draw(t_map *map, t_vars *vars)
{
	t_pos	pos;
        int     i;
        int     j;

        i = 0;
        while (i <= (int)map->row)
        {
                j = 0;
                while (j < (int)map->col)
                {
                    pos.now[0] = i * DIST;
                    pos.now[1] = j * DIST;
                    pos.next[0] = i * DIST;
                    pos.next[1] = (j + 1) * DIST;
                    draw_line(vars, &pos);
                    j++;
                }
                i++;
        }
        i = 0;
        while (i < (int)map->row)
        {
            j = 0;
            while (j <= (int)map->col)
            {
                pos.now[0] = i * DIST;
                pos.now[1] = j * DIST;
                pos.next[0] = (i + 1) * DIST;
                pos.next[1] = j * DIST;
                draw_line(vars, &pos);
                j++;
            }
            i++;
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
	vars.win = mlx_new_window(vars.mlx, SIZE, SIZE, "test");
	draw(map, &vars);
	mlx_key_hook(vars.win, close_win, &vars);
	mlx_loop(vars.mlx);
}
