#ifndef U8X4_H
#define U8X4_H
#include <stdint.h>

typedef uint32_t t_u8x4;
t_u8x4 encode_u8x4(
	uint8_t a,
	uint8_t b,
	uint8_t c,
	uint8_t d
);

uint8_t decode_u8x4_a(t_u8x4 data);
uint8_t decode_u8x4_b(t_u8x4 data);
uint8_t decode_u8x4_c(t_u8x4 data);
uint8_t decode_u8x4_d(t_u8x4 data);

// 
//

t_u8x4 t_u8x4_add(t_u8x4 a, t_u8x4 b);
t_u8x4 t_u8x4_sub(t_u8x4 a, t_u8x4 b);
t_u8x4 t_u8x4_mul(t_u8x4 a, t_u8x4 b);
t_u8x4 t_u8x4_div(t_u8x4 a, t_u8x4 b);

#endif
