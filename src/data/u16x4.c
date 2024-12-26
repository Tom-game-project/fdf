#include <stdint.h>
#include <stdbool.h>
#include "u16x4.h"
#include "print_data.h"
#include "u8x4.h"

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
	return ((uint16_t) ((data >> 32) & 0xFFFF));
}

uint16_t decode_u16x4_c(t_u16x4 data)
{
	return ((uint16_t) ((data >> 16) & 0xFFFF));
}

uint16_t decode_u16x4_d(t_u16x4 data)
{
	return ((uint16_t) (data & 0xFFFF));
}

/// スケールを変換します
t_u8x4 conv_u16x4_to_u8x4(t_u16x4 data)
{
	return (encode_u8x4(
			(uint8_t) (decode_u16x4_a(data) >> 8),
			(uint8_t) (decode_u16x4_b(data) >> 8),
			(uint8_t) (decode_u16x4_c(data) >> 8),
			(uint8_t) (decode_u16x4_d(data) >> 8)
	));
}

t_u16x4 conv_u8x4_to_u16x4(t_u8x4 data)
{
	return (encode_u16x4(
			(uint16_t) (decode_u8x4_a(data) << 8),
			(uint16_t) (decode_u8x4_b(data) << 8),
			(uint16_t) (decode_u8x4_c(data) << 8),
			(uint16_t) (decode_u8x4_d(data) << 8)
	));
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

t_u16x4 t_u16x4_div_scalar(t_u16x4 a, int16_t b)
{
	return (
		encode_u16x4(
			decode_u16x4_a(a) / b,
			decode_u16x4_b(a) / b,
			decode_u16x4_c(a) / b,
			decode_u16x4_d(a) / b
		)
	);
}

static int16_t int16_add(int16_t a, int16_t b)
{
	return (a + b);
}

static int16_t int16_sub(int16_t a, int16_t b)
{
	return (a - b);
}


// TODO
// color tools


t_u16x4 t_u16x4_map(t_u16x4 a, t_u16x4 b, int16_t (*func)(int16_t a, int16_t b))
{
	return (
		encode_u16x4(
			func(decode_u16x4_a(a), decode_u16x4_a(b)),
			func(decode_u16x4_b(a), decode_u16x4_b(b)),
			func(decode_u16x4_c(a), decode_u16x4_c(b)),
			func(decode_u16x4_d(a), decode_u16x4_d(b))
		)
	);
}


t_u16x4 t_u16x4_cal_color(t_u16x4 a, t_u16x4 b, t_u8x4 map)
{
	int16_t (*func[2])(int16_t a, int16_t b);

	func[0] = int16_add;
	func[1] = int16_sub;
	return (
		encode_u16x4(
			func[decode_u8x4_a(map)](decode_u16x4_a(a), decode_u16x4_a(b)),
			func[decode_u8x4_b(map)](decode_u16x4_b(a), decode_u16x4_b(b)),
			func[decode_u8x4_c(map)](decode_u16x4_c(a), decode_u16x4_c(b)),
			func[decode_u8x4_d(map)](decode_u16x4_d(a), decode_u16x4_d(b))
		)
	);
}

t_u8x4 create_u16x4_bool_map(t_u16x4 a,t_u16x4 b, bool (*func)(int16_t a, int16_t b))
{
	return (
		encode_u8x4(
			func(decode_u16x4_a(a), decode_u16x4_a(b)),
			func(decode_u16x4_b(a), decode_u16x4_b(b)),
			func(decode_u16x4_c(a), decode_u16x4_c(b)),
			func(decode_u16x4_d(a), decode_u16x4_d(b))
		)
	);
}