
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include "i32x2.h"

int32_t t_i32x2_dot(t_i32x2 a,t_i32x2 b)
{
	return (
		de_int_x(a) * de_int_x(b) +\
		de_int_y(a) * de_int_y(b)
	);
}

int32_t t_i32x2_max(t_i32x2 a)
{
	if (de_int_x(a) < de_int_y(a))
		return (de_int_y(a));
	else
		return (de_int_x(a));
}


bool t_i32x2_eq(t_i32x2 a,t_i32x2 b)
{
	return (
		de_int_x(a) == de_int_x(b) &&
		de_int_y(a) == de_int_y(b)
	);
}
