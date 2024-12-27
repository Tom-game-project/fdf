#include <stdint.h>
#include <limits.h>
#include "u32x2.h"

// ======================= unsigned int =======================

t_u32x2 en_u32x2(uint32_t x, uint32_t y)
{
	return ((t_u32x2) ((uint64_t) x << 32) + y);
}

uint32_t de_uint_x(t_u32x2 data)
{
	return ((uint32_t) (data >> 32));
}

uint32_t de_uint_y(t_u32x2 data)
{
	return ((uint32_t) ((data << 32) >> 32));
}

t_u32x2 t_u32x2_add(t_u32x2 a, t_u32x2 b)
{
	return (en_u32x2(
		de_uint_x(a) + de_uint_x(b),
		de_uint_y(a) + de_uint_y(b)
	));
}

t_u32x2 t_u32x2_sub(t_u32x2 a, t_u32x2 b)
{
	return (en_u32x2(
		de_uint_x(a) - de_uint_x(b),
		de_uint_y(a) - de_uint_y(b)
	));
}

t_u32x2 t_u32x2_mul(t_u32x2 a, t_u32x2 b)
{
	return (en_u32x2(
		de_uint_x(a) * de_uint_x(b),
		de_uint_y(a) * de_uint_y(b)
	));
}

int32_t t_u32x2_dot(t_u32x2 a, t_u32x2 b)
{
	return (
		de_uint_x(a) * de_uint_x(b)+\
		de_uint_y(a) * de_uint_y(b)
	);
}
