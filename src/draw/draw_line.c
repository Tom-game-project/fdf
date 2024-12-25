#include <stdbool.h>
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
	return (a * (((0 < a) * 2) - 1));
}

void draw_line(void *mlx_ptr, void *mlx_win, int x0, int y0, int x1, int y1) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = 2 * (x0 < x1) - 1;
    int sy = 2 * (y0 < y1) - 1;
    int err = dx - dy;

    while (true) {
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

void draw_line2(t_mlx_ptr_win data, t_i32x2 p0, t_i32x2 p1) 
{
	t_i32x2 d = encode_i32x2(
		abs(decode_int_x(t_i32x2_sub(p0,p1))),
		abs(decode_int_y(t_i32x2_sub(p0,p1)))
	);
	t_i32x2 s = encode_i32x2(
		2 * (decode_int_x(p0) < decode_int_x(p1)) - 1,
		2 * (decode_int_y(p0) < decode_int_y(p1)) - 1
	);
	int err = decode_int_x(d) - decode_int_y(d);

	while (true) {
		mlx_pixel_put(
			data.mlx_ptr,
		       	data.mlx_win,
		       	decode_int_x(p0),
		       	decode_int_y(p0),
		       	RED
		);
		if (
				decode_int_x(p0) == decode_int_x(p1) &&
				decode_int_y(p0) == decode_int_y(p1)
		)
			break;
		if (2 * err > -decode_int_y(d)) {
		    err -= decode_int_y(d);
		    //x0 += sx;
		    p0 = t_i32x2_add(p0, encode_i32x2(decode_int_x(s), 0));
		}
		if (2 * err < decode_int_x(d)) {
		    err += decode_int_x(d);
		    // y0 += sy;
		    p0 = t_i32x2_add(p0, encode_i32x2(0, decode_int_y(s)));
		}
	}
}

