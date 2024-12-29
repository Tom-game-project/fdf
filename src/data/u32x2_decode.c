
#include "u32x2.h"

uint32_t	de_uint_x(t_u32x2 data)
{
	return ((uint32_t)(data >> 32));
}

uint32_t	de_uint_y(t_u32x2 data)
{
	return ((uint32_t)((data << 32) >> 32));
}

