#include "i32u32.h"

int32_t de_iu_x(t_i32u32 data)
{
	return ((int32_t) (data >> 32));
}

uint32_t de_iu_y(t_i32u32 data)
{
	return ((uint32_t) (data & 0xFFFFFFFF));
}
