#include "../src/data/u32x2.h"
#include <stdio.h>

int main()
{
	t_u32x2 a = encode_u32x2(10, 20);
	t_u32x2 b = encode_u32x2(30, 40);

	t_u32x2 c = a + b;
	printf("a(%d, %d)\n", decode_x(a), decode_y(a));
	printf("b(%d, %d)\n", decode_x(b), decode_y(b));
	printf("c(%d, %d)\n", decode_x(c), decode_y(c));
	return (0);
}
