#include <stdint.h>
#include <stdbool.h>

int abs(int a)
{
	return (a * (((0 < a) << 1) - 1));
}

bool int16_lt(int16_t a, int16_t b)
{
	return (a < b);
}

int16_t int16mf(int16_t a, int16_t b)
{
	return (abs(a - b));
}

int16_t shift8_func(int16_t a, int16_t b)
{
	(void) b;
	return (a << 8);
}
