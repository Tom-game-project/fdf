#ifndef U16X4_H
#define  U16X4_H

#include <stdint.h>
#include "u8x4.h"

/// # t_u8x4
/// |------------ 64bit ------------|
/// | 16bit | 16bit | 16bit | 16bit |
typedef uint64_t t_u16x4;


t_u16x4 encode_u16x4(
	uint16_t a,
	uint16_t b,
	uint16_t c,
	uint16_t d
);


uint16_t decode_u16x4_a(t_u16x4 data);
uint16_t decode_u16x4_b(t_u16x4 data);
uint16_t decode_u16x4_c(t_u16x4 data);
uint16_t decode_u16x4_d(t_u16x4 data);


// conv
t_u8x4 conv_u16x4_to_u8x4(t_u16x4 data);
t_u16x4 conv_u8x4_to_u16x4(t_u8x4 data);
//

t_u16x4 t_u16x4_add(t_u16x4 a, t_u16x4 b);
t_u16x4 t_u16x4_sub(t_u16x4 a, t_u16x4 b);
t_u16x4 t_u16x4_mul(t_u16x4 a, t_u16x4 b);
t_u16x4 t_u16x4_div(t_u16x4 a, t_u16x4 b);

#endif
