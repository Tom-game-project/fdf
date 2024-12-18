
#include <X11/X.h>
#include <X11/keysym.h>
#include "../../minilibx-linux/mlx.h"
#include "draw.h"


#define RED    0x00FF0000

/*
 * 線を描画するための関数です。
 *
 */


int draw_line_segment()
{
	return (0);
}

static int abs(int a)
{
	return (a * (((0 < a) << 1) - 1));
}

void draw_line(void *mlx_ptr, void *mlx_win, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
	mlx_pixel_put(mlx_ptr, mlx_win, x0, y0, RED);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

