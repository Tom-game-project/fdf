#include "i32x2.h"
#include <stdint.h>

t_i32x2 en_i32x2(int32_t x, int32_t y)
{
	return ((t_i32x2) ((uint64_t) x << 32) | (uint32_t)y);
}

