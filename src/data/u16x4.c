#include <stdint.h>
#include <stdbool.h>


/// # t_u8x4
/// |------------ 64bit ------------|
/// | 16bit | 16bit | 16bit | 16bit |
typedef uint64_t t_u16x4;

t_u16x4 encode_u16x4(
	uint16_t a,
	uint16_t b,
	uint16_t c,
	uint16_t d
)
{
	return (
		(t_u16x4)
		(
			 ((uint64_t) a << 48) |
			 ((uint64_t) b << 32) |
			 ((uint64_t) c << 16) |
			 ((uint64_t) d)
		)
	);
}


uint16_t decode_u16x4_a(t_u16x4 data)
{
	return ((uint16_t) (data >> 48));
}

uint16_t decode_u16x4_b(t_u16x4 data)
{
	return ((uint16_t) (data >> 32) & 0xFFFFFFFF);
}

uint16_t decode_u16x4_c(t_u16x4 data)
{
	return ((uint16_t) (data >> 16) & 0xFFFFFFFF);
}

uint16_t decode_u16x4_d(t_u16x4 data)
{
	return ((uint16_t) (data & 0xFFFFFFFF));
}

t_u16x4 t_u16x4_add(t_u16x4 a, t_u16x4 b)
{
	return (
		encode_u16x4(
			decode_u16x4_a(a) + decode_u16x4_a(b),
			decode_u16x4_b(a) + decode_u16x4_b(b),
			decode_u16x4_c(a) + decode_u16x4_c(b),
			decode_u16x4_d(a) + decode_u16x4_d(b)
		)
	);
}

t_u16x4 t_u16x4_sub(t_u16x4 a, t_u16x4 b)
{
	return (
		encode_u16x4(
			decode_u16x4_a(a) - decode_u16x4_a(b),
			decode_u16x4_b(a) - decode_u16x4_b(b),
			decode_u16x4_c(a) - decode_u16x4_c(b),
			decode_u16x4_d(a) - decode_u16x4_d(b)
		)
	);
}

t_u16x4 t_u16x4_mul(t_u16x4 a, t_u16x4 b)
{
	return (
		encode_u16x4(
			decode_u16x4_a(a) * decode_u16x4_a(b),
			decode_u16x4_b(a) * decode_u16x4_b(b),
			decode_u16x4_c(a) * decode_u16x4_c(b),
			decode_u16x4_d(a) * decode_u16x4_d(b)
		)
	);
}

t_u16x4 t_u16x4_div(t_u16x4 a, t_u16x4 b)
{
	return (
		encode_u16x4(
			decode_u16x4_a(a) / decode_u16x4_a(b),
			decode_u16x4_b(a) / decode_u16x4_b(b),
			decode_u16x4_c(a) / decode_u16x4_c(b),
			decode_u16x4_d(a) / decode_u16x4_d(b)
		)
	);
}


