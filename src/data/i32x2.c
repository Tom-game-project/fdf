#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include "i32x2.h"

// ======================= signed int =======================

t_i32x2 encode_i32x2(int32_t x, int32_t y)
{
	return ((t_i32x2) ((uint64_t) x << 32) | (uint32_t)y);
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

int32_t t_i32x2_dot(t_i32x2 a,t_i32x2 b)
{
	return (
		decode_int_x(a) * decode_int_x(b) +\
		decode_int_y(a) * decode_int_y(b)
	);
}

int32_t t_i32x2_max(t_i32x2 a)
{
	if (decode_int_x(a) < decode_int_y(a))
		return (decode_int_y(a));
	else
		return (decode_int_x(a));
}


bool t_i32x2_eq(t_i32x2 a,t_i32x2 b)
{
	return (
		decode_int_x(a) == decode_int_x(b) &&
		decode_int_y(a) == decode_int_y(b)
	);
}

/// 定数倍
t_i32x2 t_i32x2_scalar(int32_t a, t_i32x2 b)
{
	return (encode_i32x2(a * decode_int_x(b), a * decode_int_y(b)));
}
