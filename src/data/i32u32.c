#include "i32u32.h"

t_i32u32 en_i32u32(int32_t x, uint32_t y)
{
	return ((t_i32u32) ((uint64_t)(uint32_t)x << 32) | (uint32_t)y);
}

int32_t de_iu_x(t_i32u32 data)
{
	return ((int32_t) (data >> 32));
}

uint32_t de_iu_y(t_i32u32 data)
{
	return ((uint32_t) (data & 0xFFFFFFFF));
}
