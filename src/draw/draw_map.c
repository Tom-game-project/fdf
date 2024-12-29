/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:22 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 17:37:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/i32u32.h"
#include "../data/vec2d_64.h"
#include "draw.h"
#include <stdint.h>
#include <stdlib.h>

//#define VECTOR_X en_i32x2(17, 10)
//#define VECTOR_Y en_i32x2(-17, 10)
//#define VECTOR_Z en_i32x2(0, -20)

// 等角図法
// int max以上の値を入れないで！
// 横幅、縦幅ともにint_maxを超えるようなサイズのファイルは受け付けない
//
// 計算式
// ```
// x * Vec(x) + y * Vec(y) + z * Vec(z)
// ```
t_64_elem	core_expr(vec2d_64 map, t_u32x2 counter, t_vector_directions vd)
{
	t_64_elem	p;

	p.i32x2 = t_i32x2_add(
		t_i32x2_add(
			t_i32x2_scalar(
				(int) de_uint_x(counter),
			       	vd.vector_x
			),
			t_i32x2_scalar(
				(int) de_uint_y(counter),
				vd.vector_y
			)
		),
		t_i32x2_scalar(
			de_iu_x(
				get_vec2d_elem(
					map,
					de_uint_x(counter),
					de_uint_y(counter)
				).i32u32
			),
			vd.vector_z
		)
	);
	return (p);
}

/// mapは、i32u32を格納した二次元配列
/// map i32u32(z, color)
/// 帰り値は、それぞれの点の描画位置を表した座標列
/// メモリの確保に失敗した際はNULLを返却する
/// example...
/// ```
/// rarr: [[(i32, i32)]] = {
///   {(x0, y0), (.. , ..), (.. , ..), ...},
///   {(x1, y1), (.. , ..), (.. , ..), ...},
///   {(x2, y2), (.. , ..), (.. , ..), ...},
/// }
/// ```
vec2d_64 calc_map(vec2d_64 map, t_vector_directions vd)
{
	vec2d_64 rarr;
	t_u32x2 counter;

	counter = en_u32x2(0, 0);
	rarr = init_vec2d_64(
		de_uint_x(get_shape(map)),
		de_uint_y(get_shape(map))
	);
	if (rarr == NULL)
		return (NULL);
	while (de_uint_y(counter) < de_uint_y(get_shape(rarr)))
	{
		counter = en_u32x2(0, de_uint_y(counter));
		while (de_uint_x(counter) < de_uint_x(get_shape(rarr)))
		{
			set_vec2d_elem(rarr, de_uint_x(counter), de_uint_y(counter), core_expr(map, counter, vd));
			counter = t_u32x2_add(counter, en_u32x2(1, 0));
		}
		counter = t_u32x2_add(counter, en_u32x2(0, 1));
	}
	return (rarr);
}
