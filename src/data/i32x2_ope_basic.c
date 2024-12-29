#include "i32x2.h"
#include <stdint.h>

t_i32x2 t_i32x2_add(t_i32x2 a,t_i32x2 b)
{
	return (en_i32x2(
		de_int_x(a) + de_int_x(b),
		de_int_y(a) + de_int_y(b)
	));
}

t_i32x2 t_i32x2_sub(t_i32x2 a,t_i32x2 b)
{
	return (en_i32x2(
		de_int_x(a) - de_int_x(b),
		de_int_y(a) - de_int_y(b)
	));
}

t_i32x2 t_i32x2_mul(t_i32x2 a,t_i32x2 b)
{
	return (en_i32x2(
		de_int_x(a) * de_int_x(b),
		de_int_y(a) * de_int_y(b)
	));
}

/// 定数倍
t_i32x2 t_i32x2_scalar(int32_t a, t_i32x2 b)
{
	return (en_i32x2(a * de_int_x(b), a * de_int_y(b)));
}
