#include "u32x2.h"

t_u32x2	en_u32x2(uint32_t x, uint32_t y)
{
	return ((t_u32x2)((uint64_t) x << 32) + y);
}
