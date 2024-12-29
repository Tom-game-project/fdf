#include <stdint.h>
#include "i32x2.h"

int32_t de_int_x(t_i32x2 data)
{
	return ((int32_t) (data >> 32));
}

int32_t de_int_y(t_i32x2 data)
{
	return ((int32_t) (data & 0xFFFFFFFF));
}
