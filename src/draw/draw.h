/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:26 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 18:25:29 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../../minilibx-linux/mlx.h"
# include "../args/args_structs.h"
# include "../data/i32x2.h"
# include "../data/u16x4.h"
# include "../data/u32x2.h"
# include "../data/vec2d_64.h"
# include "../fdf.h"
# include <stdint.h>

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 900
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 900
# endif

typedef struct s_vector_directions	t_vector_directions;
struct								s_vector_directions
{
	t_i32x2							vector_x;
	t_i32x2							vector_y;
	t_i32x2							vector_z;
};

typedef struct s_color_info			t_color_info;
struct								s_color_info
{
	t_u16x4							s;
	t_u8x4							m;
};

typedef struct s_colordiff			t_colordiff;
struct								s_colordiff
{
	t_u16x4							s;
	t_u16x4							e;
};

typedef struct s_position			t_position;

t_vec2d_64			calc_map(t_vec2d_64 map, \
										t_vector_directions vd);
void				draw_line(t_mlx_ptr_win mlx_ptr_win, \
										t_line l, t_colorpair cp);
void				draw_back_line(t_mlx_ptr_win mlx_ptr_win, t_line l);
int					put_lines(t_mlx_data data, t_vec2d_64 arr, \
										t_vec2d_64 zcolor, \
										t_i32x2 (*func)(t_i32x2, t_mlx_data));

int					put_back_lines(t_mlx_data data, \
						t_vec2d_64 arr, t_i32x2 (*func)(t_i32x2, \
											t_mlx_data));
void				put_point(t_mlx_ptr_win data, t_i32x2 p, \
										t_u8x4 color);

enum e_result		set_map(t_vec2d_64 point_map, t_vec2d_64 map, \
						t_vector_directions vd);

#endif
