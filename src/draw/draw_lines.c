/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:16 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 17:37:13 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/i32u32.h"
#include "../data/i32x2.h"
#include "../data/vec2d_64.h"
#include "../data/u32x2.h"
#include "../args/args_structs.h"
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

int				put_lines(\
t_mlx_ptr_win mlx_ptr_win, vec2d_64 arr, vec2d_64 zcolor)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < de_uint_y(get_shape(zcolor)) - 1)
	{
		x = 0;
		while (x < de_uint_x(get_shape(zcolor)) - 1)
		{
			draw_line(mlx_ptr_win, (t_line){f(arr, x, y), f(arr, x + 1, y)},
				(t_colorpair){de_iu_y((g(zcolor, x, y))),
				de_iu_y(g(zcolor, x + 1, y))});
			draw_line(mlx_ptr_win, (t_line){f(arr, x, y), f(arr, x, y + 1)},
				(t_colorpair){de_iu_y((g(zcolor, x, y))),
				de_iu_y(g(zcolor, x, y + 1))});
			x += 1;
		}
		y += 1;
	}
	return (0);
}
