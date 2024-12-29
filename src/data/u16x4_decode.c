#include "u16x4.h"

uint16_t	de_u16x4_a(t_u16x4 data)
{
	return ((uint16_t)(data >> 48));
}

uint16_t	de_u16x4_b(t_u16x4 data)
{
	return ((uint16_t)((data >> 32) & 0xFFFF));
}

uint16_t	de_u16x4_c(t_u16x4 data)
{
	return ((uint16_t)((data >> 16) & 0xFFFF));
}

uint16_t	de_u16x4_d(t_u16x4 data)
{
	return ((uint16_t)(data & 0xFFFF));
}
