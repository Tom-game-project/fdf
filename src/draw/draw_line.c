#include <stdbool.h>
#include <stdint.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../../minilibx-linux/mlx.h"
#include "../data/u16x4.h"
#include "draw.h"

#include "../data/print_data.h"

/*
 * 線を描画するための関数です。
 *
 */

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

    while (true) 
    {
	mlx_pixel_put(mlx_ptr, mlx_win, x0, y0, 0xff);
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


static bool int16_lt(int16_t a, int16_t b)
{
	return (a < b);
}

static int16_t int16_my_func(int16_t a, int16_t b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}


static int16_t shift8_func(int16_t a, int16_t b)
{
	(void) b;
	return (a << 8);
}

void draw_line2(t_mlx_ptr_win data, t_line line, t_colordiff color_pair)
{
	t_i32x2 d;
	t_i32x2 s;
	int32_t err;
	t_u16x4 color_step;
	t_u8x4 color_map;

	d = encode_i32x2(
		abs(decode_int_x(t_i32x2_sub(line.end,line.start))),
		abs(decode_int_y(t_i32x2_sub(line.end,line.start)))
	);
	s = encode_i32x2(
		2 * (decode_int_x(line.start) < decode_int_x(line.end)) - 1,
		2 * (decode_int_y(line.start) < decode_int_y(line.end)) - 1
	);
	err = decode_int_x(d) - decode_int_y(d);
	color_step = t_u16x4_map(
		t_u16x4_div_scalar(
			t_u16x4_map(color_pair.start, color_pair.end, int16_my_func)
			,
			(int16_t) t_i32x2_max(d) // キャスト変換とエラーの処理が必要
		), 
		0,
	       shift8_func
	);
	color_map = create_u16x4_bool_map(color_pair.start, color_pair.end, int16_lt);
	while (true)
	{
		mlx_pixel_put(
			data.mlx_ptr,
		       	data.mlx_win,
		       	decode_int_x(line.start),
		       	decode_int_y(line.start),
		       	conv_u16x4_to_u8x4(color_pair.start)
		);
		color_pair.start = t_u16x4_cal_color(color_pair.start, color_step, color_map);
		// 
		if (t_i32x2_eq(line.start, line.end))
			break;
		if (2 * err > -decode_int_y(d))
		{
		    err -= decode_int_y(d);
		    line.start = t_i32x2_add(line.start, encode_i32x2(decode_int_x(s), 0));
		}
		if (2 * err < decode_int_x(d))
		{
		    err += decode_int_x(d);
		    line.start = t_i32x2_add(line.start, encode_i32x2(0, decode_int_y(s)));
		}
	}
}



void draw_line3(void *mlx_ptr, void *mlx_win, t_line line)
{
	t_i32x2 d;
	t_i32x2 s;
	int32_t err;

	d = encode_i32x2(
		//abs(x0 - x1),
		abs(decode_int_x(line.start) - decode_int_x(line.end)),
		//abs(y0 - y1) 
		abs(decode_int_y(line.start) - decode_int_y(line.end))
	);

	s = encode_i32x2(
		// 2 * (x0 < x1) - 1,
		2 * (decode_int_x(line.start) < decode_int_x(line.end)) - 1,
		//2 * (y0 < y1) - 1
		2 * (decode_int_y(line.start) < decode_int_y(line.end)) - 1
	);
	err = decode_int_x(d) - decode_int_y(d);
	while (true) 
	{
		mlx_pixel_put(mlx_ptr, mlx_win, decode_int_x(line.start), decode_int_y(line.start), 0xff);
		if (decode_int_x(line.start) == decode_int_x(line.end) && decode_int_y(line.start) == decode_int_y(line.end)) break;
		int e2 = 2 * err;
		if (e2 > -decode_int_y(d)) {
			err -= decode_int_y(d);
			//x0 += decode_int_x(s);
			line.start = t_i32x2_add(line.start, encode_i32x2(decode_int_x(s), 0));
		}
		if (e2 < decode_int_x(d)) {
			err += decode_int_x(d);
			//y0 += decode_int_y(s);
			line.start = t_i32x2_add(line.start, encode_i32x2(0, decode_int_y(s)));
		}
	}
}
