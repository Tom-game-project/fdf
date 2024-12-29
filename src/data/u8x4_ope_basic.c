
#include "u8x4.h"
#include <stdint.h>
#include <stdbool.h>

//typedef uint32_t t_u8x4;

t_u8x4 t_u8x4_add(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) + de_u8x4_a(b),
			de_u8x4_b(a) + de_u8x4_b(b),
			de_u8x4_c(a) + de_u8x4_c(b),
			de_u8x4_d(a) + de_u8x4_d(b)
		)
	);
}

t_u8x4 t_u8x4_sub(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) - de_u8x4_a(b),
			de_u8x4_b(a) - de_u8x4_b(b),
			de_u8x4_c(a) - de_u8x4_c(b),
			de_u8x4_d(a) - de_u8x4_d(b)
		)
	);
}

t_u8x4 t_u8x4_mul(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) * de_u8x4_a(b),
			de_u8x4_b(a) * de_u8x4_b(b),
			de_u8x4_c(a) * de_u8x4_c(b),
			de_u8x4_d(a) * de_u8x4_d(b)
		)
	);
}

t_u8x4 t_u8x4_div(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) / de_u8x4_a(b),
			de_u8x4_b(a) / de_u8x4_b(b),
			de_u8x4_c(a) / de_u8x4_c(b),
			de_u8x4_d(a) / de_u8x4_d(b)
		)
	);
}


