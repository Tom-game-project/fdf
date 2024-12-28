/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:26 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:28:26 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include "../../minilibx-linux/mlx.h"
#include "../data/vec2d_64.h"
#include "../data/i32x2.h"
#include "../data/u32x2.h"
#include "../data/u16x4.h"
#include "../args/args_structs.h"

typedef struct s_position t_position;

vec2d_64 calc_map(vec2d_64 map);
void draw_line(t_mlx_ptr_win mlx_ptr_win, t_line l, t_colorpair cp);
int put_lines(t_mlx_ptr_win mlx_ptr_win, vec2d_64 arr, vec2d_64 zcolor);

#endif
