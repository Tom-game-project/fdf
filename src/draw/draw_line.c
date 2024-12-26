#include <stdbool.h>
#include <stdint.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include "../../minilibx-linux/mlx.h"
#include "../data/u16x4.h"
#include "draw.h"

#include "../data/print_data.h"


#define RED 0xFF0000


/*
 * 線を描画するための関数です。
 *
 */

static int abs(int a)
{
	return (a * (((0 < a) << 1) - 1));
}

//void draw_line(void *mlx_ptr, void *mlx_win, int x0, int y0, int x1, int y1) 
//{
//    int dx = abs(x1 - x0);
//    int dy = abs(y1 - y0);
//    int sx = 2 * (x0 < x1) - 1;
//    int sy = 2 * (y0 < y1) - 1;
//    int err = dx - dy;
//
//    while (true) 
//    {
//	mlx_pixel_put(mlx_ptr, mlx_win, x0, y0, 0xff);
//        if (x0 == x1 && y0 == y1) break;
//        int e2 = 2 * err;
//        if (e2 > -dy) {
//            err -= dy;
//            x0 += sx;
//        }
//        if (e2 < dx) {
//            err += dx;
//            y0 += sy;
//        }
//    }
//}

static bool int16_lt(int16_t a, int16_t b)
{
	return (a < b);
}

static int16_t int16_my_func(int16_t a, int16_t b)
{
	//if (a < b)
	//	return (b - a);
	//else
	//	return (a - b);
	return (abs(a - b));
}

static int16_t shift8_func(int16_t a, int16_t b)
{
	(void) b;
	return (a << 8);
}

typedef struct s_color_info t_color_info;
struct s_color_info
{
	t_u16x4 s;
	t_u8x4 m;
};

///
void draw_line(void *mlx_ptr, void *mlx_win, t_line l, t_colordiff cp)
{
	t_i32x2 d,s,e;
	t_color_info ci;

	d = encode_i32x2( abs(decode_int_x(l.start) - decode_int_x(l.end)),
		abs(decode_int_y(l.start) - decode_int_y(l.end)));
	s = encode_i32x2( 2 * (decode_int_x(l.start) < decode_int_x(l.end)) - 1,
		2 * (decode_int_y(l.start) < decode_int_y(l.end)) - 1);
	e = encode_i32x2(decode_int_x(d) - decode_int_y(d), 0);
	ci.s = t_u16x4_map(t_u16x4_div_scalar(t_u16x4_map(cp.start, cp.end, int16_my_func),
		(int16_t) t_i32x2_max(d)), 0, shift8_func);
	ci.m = create_u16x4_bool_map(cp.start, cp.end, int16_lt);
	while (true)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, decode_int_x(l.start),
			decode_int_y(l.start), conv_u16x4_to_u8x4(cp.start));
		cp.start = t_u16x4_cal_color(cp.start, ci.s, ci.m);
		if (t_i32x2_eq(l.start, l.end))
			break;
		e = encode_i32x2(decode_int_x(e), 2 * decode_int_x(e));
		e = t_i32x2_sub(e, encode_i32x2(decode_int_y(d) * (decode_int_y(e) > -decode_int_y(d)),0));
		l.start = t_i32x2_add(l.start, encode_i32x2(decode_int_x(s) * (decode_int_y(e) > -decode_int_y(d)), 0));
		e = t_i32x2_add(e, encode_i32x2(decode_int_x(d) * (decode_int_y(e) < decode_int_x(d)),0));
		l.start = t_i32x2_add(l.start, encode_i32x2(0, decode_int_y(s) * (decode_int_y(e) < decode_int_x(d))));
	}
}
