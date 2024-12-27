#ifndef U16X4_H
#define  U16X4_H

#include <stdint.h>
#include "u8x4.h"

/// # t_u8x4
/// |------------ 64bit ------------|
/// | 16bit | 16bit | 16bit | 16bit |
typedef uint64_t t_u16x4;

// encode
t_u16x4 en_u16x4(
	uint16_t a,
	uint16_t b,
	uint16_t c,
	uint16_t d
);

// decode
uint16_t de_u16x4_a(t_u16x4 data);
uint16_t de_u16x4_b(t_u16x4 data);
uint16_t de_u16x4_c(t_u16x4 data);
uint16_t de_u16x4_d(t_u16x4 data);

// conv
t_u8x4 conv_u16x4_to_u8x4(t_u16x4 data);
t_u16x4 conv_u8x4_to_u16x4(t_u8x4 data);
//

t_u16x4 t_u16x4_add(t_u16x4 a, t_u16x4 b);
t_u16x4 t_u16x4_sub(t_u16x4 a, t_u16x4 b);
t_u16x4 t_u16x4_mul(t_u16x4 a, t_u16x4 b);
t_u16x4 t_u16x4_div(t_u16x4 a, t_u16x4 b);
t_u16x4 t_u16x4_div_scalar(t_u16x4 a, int16_t b);

t_u16x4 t_u16x4_map(t_u16x4 a, t_u16x4 b, int16_t (*func)(int16_t a, int16_t b));
t_u8x4 create_u16x4_bool_map(t_u16x4 a,t_u16x4 b, bool (*func)(int16_t a, int16_t b));
t_u16x4 t_u16x4_cal_color(t_u16x4 a, t_u16x4 b, t_u8x4 map);

/// mapはboolを４つ格納する
/// map [bool, bool, bool, bool]
///
t_u16x4 t_u16x4_cal_color(t_u16x4 a, t_u16x4 b, t_u8x4 map);

/// 任意の関数を定義して、u16x4の各要素に適応させる関数
t_u8x4 create_u16x4_map(t_u16x4 a,t_u16x4 b, bool (*func)(int16_t a, int16_t b));
#endif
