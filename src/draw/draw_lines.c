/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:16 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:42:48 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../args/args_structs.h"
#include "../data/i32u32.h"
#include "../data/i32x2.h"
#include "../data/u32x2.h"
#include "../data/vec2d_64.h"
#include "../fdf.h"
#include "draw.h"
#include <stdint.h>

static t_i32x2	f(vec2d_64 arr, uint32_t x, uint32_t y)
{
	return (get_vec2d_elem(arr, x, y).i32x2);
}

static t_i32u32	g(vec2d_64 arr, uint32_t x, uint32_t y)
{
	return (get_vec2d_elem(arr, x, y).i32u32);
}

int	put_lines(t_mlx_data data, vec2d_64 arr, vec2d_64 zcolor,
		t_i32x2 (*func)(t_i32x2, t_mlx_data))
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < de_uint_y(get_shape(zcolor)) - 1)
	{
		x = 0;
		while (x < de_uint_x(get_shape(zcolor)) - 1)
		{
			draw_line((t_mlx_ptr_win){data.mlx_ptr, data.mlx_win, data.mlx_img,
				data.mlx_addr}, (t_line){func(f(arr, x, y), data), func(f(arr, x
						+ 1, y), data)}, (t_colorpair){de_iu_y((g(zcolor, x,
							y))), de_iu_y(g(zcolor, x + 1, y))});
			draw_line((t_mlx_ptr_win){data.mlx_ptr, data.mlx_win, data.mlx_img,
				data.mlx_addr}, (t_line){func(f(arr, x, y), data), func(f(arr,
						x, y + 1), data)}, (t_colorpair){de_iu_y((g(zcolor, x,
							y))), de_iu_y(g(zcolor, x, y + 1))});
			x += 1;
		}
		y += 1;
	}
	return (0);
}

int	put_back_lines(t_mlx_data data, vec2d_64 arr, t_i32x2 (*func)(t_i32x2,
			t_mlx_data))
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < de_uint_y(get_shape(arr)) - 1)
	{
		x = 0;
		while (x < de_uint_x(get_shape(arr)) - 1)
		{
			draw_back_line((t_mlx_ptr_win){data.mlx_ptr, data.mlx_win,
				data.mlx_img, data.mlx_addr}, (t_line){func(f(arr, x, y), data),
				func(f(arr, x + 1, y), data)});
			draw_back_line((t_mlx_ptr_win){data.mlx_ptr, data.mlx_win,
				data.mlx_img, data.mlx_addr}, (t_line){func(f(arr, x, y), data),
				func(f(arr, x, y + 1), data)});
			x += 1;
		}
		y += 1;
	}
	return (0);
}
