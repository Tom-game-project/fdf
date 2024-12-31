/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:25:45 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:10:32 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/i32x2.h"
#include "../args/args_structs.h"
#include "stdint.h"
#include <stdint.h>

#include "draw.h"

void	put_point(t_mlx_ptr_win data, t_i32x2 p, t_u8x4 color)
{
	int32_t	x;
	int32_t	y;

	x = de_int_x(p);
	y = de_int_y(p);
	if (0 <= x && x < WINDOW_WIDTH && 0 <= y && y < WINDOW_HEIGHT)
	{
		data.mlx_addr[y * WINDOW_WIDTH + x] = color;
	}
}
