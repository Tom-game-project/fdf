#include <stdint.h>
#include <limits.h>
#include "u32x2.h"
#include "i32x2.h"

// ======================= unsigned int =======================

t_u32x2 encode_u32x2(uint32_t x, uint32_t y)
{
	return ((t_u32x2) ((uint64_t) x << 32) + y);
}

uint32_t decode_uint_x(t_u32x2 data)
{
	return ((uint32_t) (data >> 32));
}

uint32_t decode_uint_y(t_u32x2 data)
{
	return ((uint32_t) ((data << 32) >> 32));
}

t_u32x2 t_u32x2_add(t_u32x2 a, t_u32x2 b)
{
	return (encode_u32x2(
		decode_uint_x(a) + decode_uint_x(b),
		decode_uint_y(a) + decode_uint_y(b)
	));
}

t_u32x2 t_u32x2_sub(t_u32x2 a, t_u32x2 b)
{
	return (encode_u32x2(
		decode_uint_x(a) - decode_uint_x(b),
		decode_uint_y(a) - decode_uint_y(b)
	));
}

t_u32x2 t_u32x2_mul(t_u32x2 a, t_u32x2 b)
{
	return (encode_u32x2(
		decode_uint_x(a) * decode_uint_x(b),
		decode_uint_y(a) * decode_uint_y(b)
	));
}

// ======================= signed int =======================

t_i32x2 encode_i32x2(int32_t x, int32_t y)
{
	//return ((t_i32x2) ((uint64_t) x << 32) + y);
	return ((t_i32x2) ((uint64_t)(uint32_t)x << 32) | (uint32_t)y);
}

int32_t decode_int_x(t_i32x2 data)
{
	return ((int32_t) (data >> 32));
}

int32_t decode_int_y(t_i32x2 data)
{
	return ((int32_t) (data & 0xFFFFFFFF));
}


t_i32x2 t_i32x2_add(t_i32x2 a,t_i32x2 b)
{
	return (encode_i32x2(
		decode_int_x(a) + decode_int_x(b),
		decode_int_y(a) + decode_int_y(b)
	));
}

t_i32x2 t_i32x2_sub(t_i32x2 a,t_i32x2 b)
{
	return (encode_i32x2(
		decode_int_x(a) - decode_int_x(b),
		decode_int_y(a) - decode_int_y(b)
	));
}

t_i32x2 t_i32x2_mul(t_i32x2 a,t_i32x2 b)
{
	return (encode_i32x2(
		decode_int_x(a) * decode_int_x(b),
		decode_int_y(a) * decode_int_y(b)
	));
}
