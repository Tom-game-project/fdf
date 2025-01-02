/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_64.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:50 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:24:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2D_64_H
# define VEC2D_64_H

# include "../error/result.h"
# include "i32u32.h"
# include "i32x2.h"
# include "u32x2.h"

# define DATA_PADDING 1
# define SHARP 0

typedef union u_64_elem	t_64_elem;
typedef t_64_elem		*vec2d_64;

union					u_64_elem
{
	t_i32u32			i32u32;
	t_i32x2				i32x2;
	t_u32x2				u32x2;
	uint64_t			u64;
	int64_t				i64;
};

vec2d_64				init_vec2d_64(uint32_t width, uint32_t height);
t_64_elem				get_vec2d_elem(vec2d_64 data, uint32_t x, uint32_t y);
enum e_result			set_vec2d_elem(vec2d_64 data, uint32_t x, uint32_t y,
							t_64_elem i);
t_u32x2					get_shape(vec2d_64 arr);

enum e_result			add_vec_i32x2(vec2d_64 arr, t_i32x2 a);

t_i32x2					get_we(vec2d_64 arr);
t_i32x2					get_ns(vec2d_64 arr);

#endif
