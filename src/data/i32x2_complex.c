#include "i32x2.h"

t_i32x2 t_i32x2_complex_mul(t_i32x2 a, t_i32x2 b)
{
	return (
		en_i32x2(
			de_int_x(a) * de_int_x(b) -\
			de_int_y(a) * de_int_y(b),
			de_int_x(a) * de_int_y(b) +\
			de_int_x(b) * de_int_y(a)
		)
	);
}
