/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:01 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:44:58 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include "../args/args_structs.h"
#include "../data/u16x4.h"
#include "draw.h"
#include "draw_line_helper.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * 線を描画するための関数です。
 *
 */

// void draw_line(void *mlx_ptr, void *mlx_win, int x0, int y0, int x1, int y1)
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
//        if (x0 == x1 && y0 == y1) break ;
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

/// de_int_x
static int32_t	x(t_i32x2 a)
{
	return (de_int_x(a));
}

/// de_int_y
static int32_t	y(t_i32x2 a)
{
	return (de_int_y(a));
}

void	draw_line_helper(t_mlx_ptr_win mlx_ptr_win, t_line l,
		t_colordiff cp)
{
	t_color_info	ci;

	t_i32x2 *(dummy), d, s, e;
	(void)dummy;
	d = en_i32x2(abs(x(l.s) - x(l.e)), abs(y(l.s) - y(l.e)));
	s = en_i32x2(((x(l.s) < x(l.e)) << 1) - 1, ((y(l.s) < y(l.e)) << 1) - 1);
	e = en_i32x2(x(d) - y(d), 0);
	if (t_i32x2_max(d) == 0)
		return ;
	ci.s = t_u16x4_div_scalar(t_u16x4_map(cp.s, cp.e, int16mf), \
		(uint16_t)t_i32x2_max(d));
	ci.m = create_u16x4_bool_map(cp.s, cp.e, int16_gt);
	while (true)
	{
		put_point(mlx_ptr_win, l.s, conv_u16x4_to_u8x4(cp.s));
		cp.s = t_u16x4_cal_color(cp.s, ci.s, ci.m);
		if (t_i32x2_eq(l.s, l.e))
			break ;
		e = en_i32x2(x(e), x(e) << 1);
		e = t_i32x2_sub(e, en_i32x2(y(d) * (y(e) > -y(d)), 0));
		l.s = t_i32x2_add(l.s, en_i32x2(x(s) * (y(e) > -y(d)), 0));
		e = t_i32x2_add(e, en_i32x2(x(d) * (y(e) < x(d)), 0));
		l.s = t_i32x2_add(l.s, en_i32x2(0, y(s) * (y(e) < x(d))));
	}
}

void	draw_back_line_helper(t_mlx_ptr_win mlx_ptr_win, t_line l)
{
	t_i32x2 *(dummy), d, s, e;
	(void)dummy;
	d = en_i32x2(abs(x(l.s) - x(l.e)), abs(y(l.s) - y(l.e)));
	s = en_i32x2(((x(l.s) < x(l.e)) << 1) - 1, ((y(l.s) < y(l.e)) << 1) - 1);
	e = en_i32x2(x(d) - y(d), 0);
	while (true)
	{
		put_point(mlx_ptr_win, l.s, 0x0);
		if (t_i32x2_eq(l.s, l.e))
			break ;
		e = en_i32x2(x(e), x(e) << 1);
		e = t_i32x2_sub(e, en_i32x2(y(d) * (y(e) > -y(d)), 0));
		l.s = t_i32x2_add(l.s, en_i32x2(x(s) * (y(e) > -y(d)), 0));
		e = t_i32x2_add(e, en_i32x2(x(d) * (y(e) < x(d)), 0));
		l.s = t_i32x2_add(l.s, en_i32x2(0, y(s) * (y(e) < x(d))));
	}
}
