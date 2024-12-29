#include "u8x4.h"

uint8_t de_u8x4_a(t_u8x4 data)
{
	return ((uint8_t) (data >> 24));
}

uint8_t de_u8x4_b(t_u8x4 data)
{
	return ((uint8_t) (data >> 16) & 0xFFFFFFFF);
}

uint8_t de_u8x4_c(t_u8x4 data)
{
	return ((uint8_t) (data >> 8) & 0xFFFFFFFF);
}

uint8_t de_u8x4_d(t_u8x4 data)
{
	return ((uint8_t) (data & 0xFFFFFFFF));
}

