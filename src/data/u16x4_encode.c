#include "u16x4.h"

t_u16x4	en_u16x4(
	uint16_t a,
	uint16_t b,
	uint16_t c,
	uint16_t d
)
{
	return (
		(t_u16x4)
		(
			((uint64_t) a << 48) | \
			((uint64_t) b << 32) | \
			((uint64_t) c << 16) | \
			((uint64_t) d)
		)
	);
}
