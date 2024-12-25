#include "i32x2.h"
#include "u32x2.h"
#include "i32u32.h"
#include "u16x4.h"
#include "u8x4.h"
#include <stdio.h>

// 表示のための関数郡
int print_u32x2(t_u32x2 data)
{
	return printf("(%u, %u) ", decode_uint_x(data) ,decode_uint_y(data));
}

int print_i32x2(t_i32x2 data)
{
	return printf("(%d, %d) ", decode_int_x(data) ,decode_int_y(data));
}

int print_i32u32(t_i32u32 data)
{
	return printf("(%d, %u) ", decode_iu_x(data), decode_iu_y(data));
}

int print_u16x4(t_u16x4 data)
{
	return printf("t_u16x4(%d %d %d %d)\n", 
		decode_u16x4_a(data),
		decode_u16x4_b(data),
		decode_u16x4_c(data),
		decode_u16x4_d(data)
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
