#include "i32x2.h"
#include "u32x2.h"
#include "i32u32.h"
#include "u16x4.h"
#include "u8x4.h"
#include "vec2d_64.h"
#include <stdio.h>

// 表示のための関数郡
int print_u32x2(t_u32x2 data)
{
	return printf("(%u, %u) ", de_uint_x(data) ,de_uint_y(data));
}

int print_i32x2(t_i32x2 data)
{
	return printf("(%d, %d) ", de_int_x(data) ,de_int_y(data));
}

int print_i32u32(t_i32u32 data)
{
	return printf("(%d, %x) ", de_iu_x(data), de_iu_y(data));
}

int print_u16x4(t_u16x4 data)
{
	return printf("t_u16x4(%d %d %d %d)\n", 
		de_u16x4_a(data),
		de_u16x4_b(data),
		de_u16x4_c(data),
		de_u16x4_d(data)
	);
}

int print_u8x4(t_u8x4 data)
{
	return printf("t_u8x4(%d %d %d %d)\n", 
		decode_u8x4_a(data),
		decode_u8x4_b(data),
		decode_u8x4_c(data),
		decode_u8x4_d(data)
	);
}

/// i32u32を格納した二次元配列を表示します
int print_vec2d_elem_i32u64(vec2d_64 arr)
{
	t_64_elem tmp;

	for (uint32_t y = 0; y < de_uint_y(get_shape(arr)); y++)
	{
		for (uint32_t x = 0; x < de_uint_x(get_shape(arr)); x++)
		{
			tmp.i32u32 = get_vec2d_elem(arr, x, y).i32u32;
			print_i32u32(tmp.i32u32);
		}
		printf("\n");
	}
	return (0);
}

int print_vec2d_elem_i32x2(vec2d_64 arr)
{
	t_64_elem tmp;

	for (uint32_t y = 0; y < de_uint_y(get_shape(arr)); y++)
	{
		for (uint32_t x = 0; x < de_uint_x(get_shape(arr)); x++)
		{
			tmp.i32x2 = get_vec2d_elem(arr, x, y).i32x2;
			print_i32x2(tmp.i32x2);
		}
		printf("\n");
	}
	return (0);
}

