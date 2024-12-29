#include "u8x4.h"

t_u8x4 en_u8x4(
	uint8_t a,
	uint8_t b,
	uint8_t c,
	uint8_t d
)
{
	return (
		(t_u8x4)
		(
			 ((uint32_t) a << 24) |
			 ((uint32_t) b << 16) |
			 ((uint32_t) c << 8) |
			 ((uint32_t) d)
		)
	);
}
