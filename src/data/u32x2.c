#include <stdint.h>
#include <limits.h>
#include "u32x2.h"

t_u32x2 encode_u32x2(uint32_t x, uint32_t y)
{
	return ((t_u32x2) ((uint64_t) x << 32) + y);
}

uint32_t decode_x(t_u32x2 data)
{
	return ((uint32_t) (data >> 32));
}

uint32_t decode_y(t_u32x2 data)
{
	return ((uint32_t) ((data << 32) >> 32));
}
