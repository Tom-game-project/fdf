#include "../data/i32u32.h"
#include "../data/vec2d_64.h"
#include <stdint.h>
#include <stdlib.h>

#define VECTOR_X encode_i32x2(17, 10)
#define VECTOR_Y encode_i32x2(-17, 10)
#define VECTOR_Z encode_i32x2(0, -20)

// 等角図法
// int max以上の値を入れないで！
// 横幅、縦幅ともにint_maxを超えるようなサイズのファイルは受け付けない
//
// 計算式
// ```
// x * Vec(x) + y * Vec(y) + z * Vec(z)
// ```
t_64_elem core_expr(vec2d_64 map, t_u32x2 counter)
{
	t_64_elem p;

	p.i32x2 = t_i32x2_add(
		t_i32x2_add(
			t_i32x2_scalar(
				(int) decode_uint_x(counter),
			       	VECTOR_X
			),
			t_i32x2_scalar(
				(int) decode_uint_y(counter),
				VECTOR_Y
			)
		),
		t_i32x2_scalar(
			decode_iu_x(
				get_vec2d_elem(
					map,
					decode_uint_x(counter),
					decode_uint_y(counter)
				).i32u32
			),
			VECTOR_Z
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
vec2d_64 calc_map(vec2d_64 map)
{
	vec2d_64 rarr;
	t_u32x2 counter;

	counter = encode_u32x2(0, 0);
	rarr = init_vec2d_64(
		decode_uint_x(get_shape(map)),
		decode_uint_y(get_shape(map))
	);
	if (rarr == NULL)
		return (NULL);
	while (decode_uint_y(counter) < decode_uint_y(get_shape(rarr)))
	{
		counter = encode_u32x2(0, decode_uint_y(counter));
		while (decode_uint_x(counter) < decode_uint_x(get_shape(rarr)))
		{
			set_vec2d_elem(rarr, decode_uint_x(counter), decode_uint_y(counter), core_expr(map, counter));
			counter = t_u32x2_add(counter, encode_u32x2(1, 0));
		}
		counter = t_u32x2_add(counter, encode_u32x2(0, 1));
	}
	return (rarr);
}
