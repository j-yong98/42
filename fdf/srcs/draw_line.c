#include "fdf.h"

static  void    draw_y(t_vars *vars, t_pos *pos, int dy, int dx)
{
    int y;
    int x;
    int p;

    y = pos->now[0];
    x = pos->now[1];
    p = 2 * dx - dy;
    while (y <= pos->next[0])
    {
        mlx_pixel_put(vars->mlx, vars->win, x, y, 0xffffff);
        y++;
        if (p < 0)
            p += 2 * dx;
        else
        {
            p += 2 * dx - dy;
            x++;
        }
        
    }
}

static  void    draw_x(t_vars *vars, t_pos *pos, int dy, int dx)
{
    int y;
    int x;
    int p;

    y = pos->now[0];
    x = pos->now[1];
    p = 2*dy - dx;
    while (x <= pos->next[1])
    {
        mlx_pixel_put(vars->mlx, vars->win, x, y, 0xffffff);
        x++;
        if (p < 0)
            p += 2 * dy;
        else
        {
            p += 2 * dy - 2 * dx;
            y++;
        }
    }
}

void    draw_line(t_vars *vars, t_pos* pos)
{
    int dy;
    int dx;

    dy = abs(pos->now[0] - pos->next[0]);
    dx = abs(pos->now[1] - pos->next[1]);
    printf("x : %d, y : %d, dx : %d, dy : %d\n", pos->now[1], pos->now[0], dx, dy);
    if (dy > dx)
        draw_y(vars, pos, dy, dx);
    else
        draw_x(vars, pos, dy, dx);
}
